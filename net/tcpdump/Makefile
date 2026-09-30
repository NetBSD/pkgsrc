# $NetBSD: Makefile,v 1.58 2026/09/30 18:59:12 adam Exp $

DISTNAME=	tcpdump-4.99.7
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tcpdump.org/
COMMENT=	Network monitoring tool
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS.Darwin+=	--disable-universal
# drop privileges when running
CONFIGURE_ARGS+=	--with-user=_tcpdump
CONFIGURE_ARGS+=	--with-chroot=${VARBASE}/tcpdump

BUILD_DEFS+=	VARBASE
OWN_DIRS=	${VARBASE}/tcpdump
PKG_GROUPS=	_tcpdump
PKG_USERS=	_tcpdump:_tcpdump

.include "options.mk"

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=1.9.1
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
