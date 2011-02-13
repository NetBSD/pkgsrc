# $NetBSD: Makefile,v 1.16 2011/02/13 00:20:24 rumko Exp $
#

DISTNAME=	tinc-1.0.13
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.tinc-vpn.org/packages/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.tinc-vpn.org/
COMMENT=	Virtual Private Network (VPN) daemon
LICENSE=	gnu-gpl-v2

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
