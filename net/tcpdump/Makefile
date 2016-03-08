# $NetBSD: Makefile,v 1.41 2016/03/08 12:53:34 adam Exp $

DISTNAME=	tcpdump-4.7.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcpdump.org/
COMMENT=	Network monitoring tool
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS.Darwin+=	--disable-universal

.include "options.mk"

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
