# $NetBSD: Makefile,v 1.55 2023/10/24 22:10:34 wiz Exp $

DISTNAME=	tcpdump-4.99.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tcpdump.org/
COMMENT=	Network monitoring tool
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS.Darwin+=	--disable-universal

BUILD_DEFS+=		VARBASE
OWN_DIRS=		${VARBASE}/tcpdump
PKG_GROUPS=		_tcpdump
PKG_USERS=		_tcpdump:_tcpdump

# drop privileges when running
CONFIGURE_ARGS+=	--with-user=_tcpdump
CONFIGURE_ARGS+=	--with-chroot=${VARBASE}/tcpdump

.include "options.mk"

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=1.9.1
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
