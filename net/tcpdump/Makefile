# $NetBSD: Makefile,v 1.43 2017/02/02 18:08:29 maya Exp $

DISTNAME=	tcpdump-4.9.0
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
