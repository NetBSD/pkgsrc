# $NetBSD: Makefile,v 1.17 2024/05/29 16:33:24 adam Exp $

DISTNAME=		libpst-0.6.76
PKGNAME=		${DISTNAME:S/libpst/pst-utils/}
PKGREVISION=		12
CATEGORIES=		mail
MASTER_SITES=		https://www.five-ten-sg.com/libpst/packages/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.five-ten-sg.com/libpst/
COMMENT=		Tools for reading and converting Outlook PST files
LICENSE=		gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-dii
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--enable-libpst-shared
CONFIGURE_ARGS+=	--disable-static-tools

USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE=	libpst.pc.in

.include "../../devel/libgsf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
