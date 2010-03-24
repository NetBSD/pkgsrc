# $NetBSD: Makefile,v 1.9 2010/03/24 19:43:25 asau Exp $

PKGNAME=	usrp-docs-${VERSION}
PKGREVISION=	2
COMMENT=	Documentation for the usrp module

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

USE_TOOLS+=	make
CONFIGURE_ARGS+=--enable-doxygen
CONFIGURE_ARGS+=--docdir=${LOCALBASE}/share/doc/gnuradio/usrp

BUILD_DEPENDS+=	doxygen>=1.6.1:../../devel/doxygen
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

BUILD_DIRS=	usrp/doc

DOCDIR=		${PREFIX}/share/doc/usrp-${PKGVERSION_NOREV}
INSTALLATION_DIRS=	${DOCDIR}

do-install:
	cp -r ${WRKSRC}/usrp/doc/html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/usrp/doc/usrp_guide.html ${DESTDIR}${DOCDIR}/html

.include "../../ham/usrp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
