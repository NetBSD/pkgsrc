# $NetBSD: Makefile,v 1.38 2006/08/22 20:17:23 joerg Exp $
#

DISTNAME=		plt-${DRSCHEME_VERSION}-src-unix
PKGNAME=		drscheme-${DRSCHEME_VERSION}
DIST_SUBDIR=		${PKGNAME_NOREV:C/-[0-9]*//}/${PKGNAME_NOREV:C/.*-([0-9]*)/\1/}
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://download.plt-scheme.org/bundles/${DRSCHEME_VERSION}/plt/ 	\
			http://download.plt-scheme.org/doc/${DRSCHEME_VERSION}/bundles/ 	\
			http://www.cs.utah.edu/plt/download/${DRSCHEME_VERSION}/plt/ 		\
			ftp://ftp.pasteur.fr/pub/computing/Scheme/plt-scheme/${DRSCHEME_VERSION}/plt/ \
			ftp://archive.informatik.uni-tuebingen.de/unix/language/plt/${DRSCHEME_VERSION}/plt/ \
			ftp://morpheus.wish.com.mx/pub/plt/${DRSCHEME_VERSION}/plt/
DISTFILES+=		${DOCFILES} ${DISTNAME}${EXTRACT_SUFX}
DOCFILES=		mred-doc.plt framework-doc.plt tools-doc.plt tex2page-doc.plt
EXTRACT_SUFX=		.tgz
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.drscheme.org/
COMMENT=		R4RS-compliant and nearly R5RS-compliant scheme tailored for teaching

CONFLICTS+=		mzscheme-[0-9]*

WRKSRC=                 ${WRKDIR}/plt/src
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes

USE_LANGUAGES=		c c++

SUBST_CLASSES+=		x11root
SUBST_STAGE.x11root=	post-patch
SUBST_FILES.x11root=	${WRKDIR}/plt/collects/sgl/makefile.ss
SUBST_SED.x11root=	-e 's,/usr/X11R6,${X11BASE},'

DRSCHEME_VERSION=	209

# XXX: we pass this as the prefix to the configure script (see below) so
#      the mzc compiler finds all the right includes and libs
PLT_HOME=		${PREFIX}/lib/plt

PROGRAMS=	drscheme framework-test framework-test-engine games help-desk \
		mred mzc mzpp mzscheme mztext pdf-slatex setup-plt slatex     \
		slideshow tex2page web-server web-server-monitor web-server-text

post-patch:
	@for patchee in 						\
		${WRKDIR}/plt/bin/mred 					\
		${WRKDIR}/plt/bin/mzscheme 				\
		${WRKDIR}/plt/man/man1/mzscheme.1 			\
		${WRKDIR}/plt/collects/slibinit/init.ss 		\
		${WRKDIR}/plt/collects/dynext/compile-unit.ss		\
		${WRKSRC}/mzscheme/src/makeexn 				\
		${WRKDIR}/plt/man/man1/drscheme.1 			\
		${WRKDIR}/plt/man/man1/mred.1; do 			\
			${MV} -f $$patchee ${WRKSRC}/foo ; 		\
			${SED} -e 's|@PREFIX@|${PREFIX}|' <${WRKSRC}/foo \
				 > $$patchee ; 				\
	done;
	@${MV} -f ${WRKSRC}/mred/Makefile.in ${WRKSRC}/foo
	@${SED} -e 's|@X11PREFIX@|${X11PREFIX}|' < ${WRKSRC}/foo > ${WRKSRC}/mred/Makefile.in
	@${RM} -f ${WRKSRC}/foo
	@${FIND} ${WRKDIR} -name '*.orig' -print | ${XARGS} ${RM} -f

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/../man/man1/*.1 ${PREFIX}/man/man1/
	@cd ${PREFIX}/lib/plt && PATH="${OLD_PATH}" ${SH} install || ${TRUE}
.for f in ${PROGRAMS}
	@cd ${PREFIX}/bin && ${LN} -s ../lib/plt/bin/${f}
.endfor
.for f in ${DOCFILES}
	${PREFIX}/bin/setup-plt ${DISTDIR}/${DIST_SUBDIR}/${f}
.endfor

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# See comment above.
CONFIGURE_ARGS+=	--prefix=${PLT_HOME:Q}

# XXX: Gack.  Ugly hackery to have the install process run with the regular
#      PATH.
.for _dir_ in ${PATH:C/:/ /g}
.  if empty(PREPEND_PATH:M${_dir_})
OLD_PATH:=	${_dir_}:${OLD_PATH}
.  endif
.endfor
