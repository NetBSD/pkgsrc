# $NetBSD: Makefile,v 1.10 1998/07/17 14:33:52 tv Exp $
#

DISTNAME=       jpegsrc.v6b
PKGNAME=        jpeg-6b
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=	mycroft@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

WRKSRC=         ${WRKDIR}/jpeg-6b
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBTOOL=${PREFIX}/bin/libtool
INSTALL_TARGET= install install-lib

.include "../../mk/bsd.pkg.mk"
