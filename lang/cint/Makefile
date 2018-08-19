# $NetBSD: Makefile,v 1.34 2018/08/19 20:16:40 wiz Exp $

DISTNAME=		cint-5.16.19-source
PKGNAME=		${DISTNAME:S/-source//}
CATEGORIES=		lang
MASTER_SITES=		https://root.cern.ch/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hanno.jp/gotom/Cint.html
COMMENT=		C/C++ interpreter
LICENSE=		mit

USE_TOOLS+=		bash gmake pax
USE_LANGUAGES=		c c++

CONFIG_SHELL=		${BASH}

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

CONFIGURE_ARGS+=	--arch=netbsd
CONFIGURE_ARGS+=	--readline=${PREFIX}/lib/libreadline.so

USE_LANGUAGES=		c c++

HAS_CONFIGURE=			yes
CFLAGS+=			-Wno-write-strings
CXXFLAGS+=			-Wno-write-strings
LDFLAGS+=			${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS+=			${COMPILER_RPATH_FLAG}${PREFIX}/cint/lib
CONFIGURE_ENV+=			CFLAGS_ADD=${CFLAGS:Q}
CONFIGURE_ENV+=			CXXFLAGS_ADD=${CXXFLAGS:Q}
CONFIGURE_ENV+=			LDFLAGS_ADD=${LDFLAGS:Q}
CONFIGURE_ENV+=			SOFLAGS_ADD=${LDFLAGS:Q}

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/cint/lib
BUILDLINK_PASSTHRU_RPATHDIRS+=	${PREFIX}/cint/lib

BUILD_TARGET=			# empty string required (override "all")

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
MAKE_ENV+=		CFLAGS_NO_RETURN_TYPE=-Wno-error=return-type
.endif

INSTALLATION_DIRS+=	bin cint cint/lib share/doc/cint
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man2 ${PKGMANDIR}/man3

post-extract:
	${FIND} ${WRKSRC} -depth -type d -name CVS -exec ${RM} -rf {} \;
	${FIND} ${WRKSRC} -type f -name .cvsignore -exec ${RM} -f {} \;
	${SED} "s;XXXPREFIXXXX;${PREFIX};g" <${FILESDIR}/cint.sh \
		>${WRKSRC}/cint.sh


# We do not want these files to be installed
pre-install:
	${RM} -f ${WRKSRC}/include/Makeit
	${RM} -f ${WRKSRC}/include/make*

do-install:
.for f in cint makecint
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/cint
.endfor
	${INSTALL_DATA} ${WRKSRC}/inc/G__ci.h ${DESTDIR}${PREFIX}/cint
	${INSTALL_PROGRAM} ${WRKSRC}/libcint.so ${DESTDIR}${PREFIX}/cint/lib
	${INSTALL_SCRIPT} ${WRKSRC}/cint.sh ${DESTDIR}${PREFIX}/bin/cint
	${RUN} cd ${DESTDIR}${PREFIX}/bin && ${LN} -sf cint makecint
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/cint
	${RUN} cd ${WRKSRC} && ${PAX} -rw include stl ${DESTDIR}${PREFIX}/cint
# Install demos
	${RUN} cd ${WRKSRC} && ${PAX} -rw demo ${DESTDIR}${PREFIX}/cint
	${RUN} cd ${WRKSRC}/lib \
		&& ${PAX} -rw prec_stl ${DESTDIR}${PREFIX}/cint/lib
.for f in \
	bytecode.txt cint.txt cintapi.txt extlib.txt ifdef.txt limitati.txt \
	limitnum.txt makecint.txt message.txt ref.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${f} \
		${DESTDIR}${PREFIX}/share/doc/cint
.endfor
.for f in \
	cint.1 makecint.1 garbage.2 unique.2 array.h.3 fft.h.3 statistics.h.3
	${INSTALL_MAN} ${WRKSRC}/doc/man${f:E}/${f} \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man${f:E}/${f}
.endfor
# Resolve conflict with devel/man-pages
.for f in \
	security.2
	${INSTALL_MAN} ${WRKSRC}/doc/man${f:E}/${f} \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man${f:E}/cint_${f}
.endfor


.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
