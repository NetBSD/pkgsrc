# $NetBSD: Makefile,v 1.12 2009/04/18 19:27:11 tonnerre Exp $
#

DISTNAME=	tinc-1.0.9
CATEGORIES=	net
MASTER_SITES=	http://www.tinc-vpn.org/packages/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.tinc-vpn.org/
LICENSE=	gnu-gpl-v2
COMMENT=	Virtual Private Network (VPN) daemon

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_TOOLS+=	msgfmt

.include "../../archivers/lzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
