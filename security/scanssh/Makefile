# $NetBSD: Makefile,v 1.41 2024/12/10 12:01:25 wiz Exp $

DISTNAME=	scanssh-2.1
PKGREVISION=	17
CATEGORIES=	security
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://monkey.org/~provos/scanssh/
COMMENT=	SSH remote version scanner
LICENSE=	original-bsd

GNU_CONFIGURE=		YES

.include "../../devel/libevent/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
