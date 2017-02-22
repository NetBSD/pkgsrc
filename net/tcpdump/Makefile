# $NetBSD: Makefile,v 1.44 2017/02/22 19:05:44 maya Exp $

DISTNAME=	tcpdump-4.9.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcpdump.org/
COMMENT=	Network monitoring tool
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS.Darwin+=	--disable-universal

BUILD_DEFS+=		VARBASE
PKG_USERS=		_tcpdump
OWN_DIRS=		${VARBASE}/tcpdump

# drop privileges when running
CONFIGURE_ARGS+=	--with-user=_tcpdump
CONFIGURE_ARGS+=	--with-chroot=${VARBASE}/tcpdump

.include "options.mk"

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
