# $NetBSD: Makefile,v 1.9 1998/07/04 09:37:29 mycroft Exp $
#

DISTNAME=       jpegsrc.v6b
PKGNAME=        jpeg-6b
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=	mycroft@netbsd.org

WRKSRC=         ${WRKDIR}/jpeg-6b
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --enable-static
INSTALL_TARGET= install install-lib

.include "../../mk/bsd.pkg.mk"
