# $NetBSD: Makefile,v 1.1 2019/11/15 11:09:15 sborrill Exp $
#

DISTNAME=		libpst-0.6.72
PKGNAME=		${DISTNAME:S/libpst/pst-utils/}
CATEGORIES=		mail
MASTER_SITES=		https://www.five-ten-sg.com/libpst/packages/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.five-ten-sg.com/libpst/
COMMENT=		Tools for reading and converting PST files
LICENSE=		gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-dii
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--enable-libpst-shared
CONFIGURE_ARGS+=	--disable-static-tools

USE_TOOLS+=		pkg-config

.include "../../devel/libgsf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
