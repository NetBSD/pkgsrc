# $NetBSD: Makefile,v 1.4 2019/11/04 21:43:38 rillig Exp $

.include "../../textproc/libhighlight/Makefile.common"

PKGNAME=	libhighlight-${VERSION}
COMMENT+=	(shared library)

BUILD_TARGET=		lib-shared

EGDIR=			${PREFIX}/share/examples/highlight
CONF_FILES=		${EGDIR}/filetypes.conf			\
			${PKG_SYSCONFDIR}/filetypes.conf

INSTALLATION_DIRS=	lib

pre-install:
	rm -f ${WRKSRC}/extras/swig/*.orig

post-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/src/libhighlight.la \
		${DESTDIR}${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
