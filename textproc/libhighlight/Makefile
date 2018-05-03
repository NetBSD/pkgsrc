# $NetBSD: Makefile,v 1.2 2018/05/03 13:13:51 schmonz Exp $

.include "../../textproc/libhighlight/Makefile.common"

PKGNAME=		libhighlight-${VERSION}
COMMENT+=		 (shared library)

USE_LIBTOOL=		yes

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
