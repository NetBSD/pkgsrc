# $NetBSD: Makefile,v 1.1 2025/03/03 02:35:31 scole Exp $

PKGVERSION=	2.0.1
DISTNAME=	Img-${PKGVERSION_NOREV}
PKGNAME=	tkimg-${PKGVERSION}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tkimg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tkimg.sourceforge.net/
COMMENT=	Add support for several image formats to Tk
LICENSE=	modified-bsd

.include "options.mk"

WRKSRC=			${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=		yes
USE_TOOLS+=		cat chmod gmake ls mkdir mv sed tclsh
TEST_TARGET=		tests

INSTALLATION_DIRS+=	lib/Img${PKGVERSION_NOREV} ${PKGMANDIR}/mann
TOOL_DEPENDS+=		tcllib-[0-9]*:../../devel/tcllib

# xxx configure script doesn't grok NetBSD 64bit:
# WARNING: 64bit support being disabled -- don't know magic for this platform
.if ${MACHINE_ARCH} == "sparc64"
CONFIGURE_ARGS+=	--enable-64bit-vis
.else
.  for plat in ${LP64PLATFORMS}
.    if ${MACHINE_PLATFORM:M${plat}}
CONFIGURE_ARGS+=	--enable-64bit
.    endif
.  endfor
.endif

# tkimg has the source code of these graphic libraries embedded in the
# its distribution and are heavily intertwined with its build.  To
# separate them out and use the pkgsrc libraries instead would require
# a large amount of work, as they appear dependent on the text of the
# source code itself.  check vulnerabilities, may be better than nothing
EMB_SRC=	jpeg-9.6.0 png-1.6.44 tiff-4.7.0 zlib-1.3.1
VFILE=		${_EXTRACT_PKGVULNDIR:sh}/pkg-vulnerabilities
pre-fetch:
.if exists(${VFILE})
.  if !empty(ALLOW_VULNERABLE_PACKAGES:tl:Mno)
	for i in ${EMB_SRC}; do \
		${PKG_ADMIN} audit-pkg $$i || \
		 { ${FAIL_MSG} "embedded source $$i has vulnerabilities. "\
			"Define ALLOW_VULNERABLE_PACKAGES if necessary"; \
		 exit 1; } \
	done
.  endif
.endif

# xxx shared libs
GENERATE_PLIST+=	(cd ${WRKSRC}/Img/exec_prefix && \
			${LS} lib/Img/* | ${SED} -e 's/lib\/Img/lib\/Img${PKGVERSION_NOREV}/');

do-install:
	cd ${WRKSRC} && ${GMAKE} collate
	${MKDIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/mann \
		${DESTDIR}${PREFIX}/include \
		${DESTDIR}${PREFIX}/lib/Img${PKGVERSION_NOREV}
	${INSTALL_DATA} ${WRKSRC}/Img/prefix/include/*.h \
		${DESTDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/Img/exec_prefix/lib/*.sh \
		${DESTDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/Img/exec_prefix/lib/Img/* \
		${DESTDIR}${PREFIX}/lib/Img${PKGVERSION_NOREV}
	${INSTALL_DATA} ${WRKSRC}/Img/exec_prefix/lib/Img/pkgIndex.tcl \
		${DESTDIR}${PREFIX}/lib/Img${PKGVERSION_NOREV}
	for i in ${WRKSRC}/doc/*.man; do \
		dtplite -ext n -o ${DESTDIR}${PREFIX}/${PKGMANDIR}/mann nroff $$i; \
	done

tests:
	cd ${WRKSRC}/tests/demo && ${TCLSH} demo.tcl
	cd ${WRKSRC}/tests/visualtests && ${TCLSH} RunTests --auto --verbose

# xxx already in src distribution file, see note above
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
#.include "../../graphics/tiff/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
