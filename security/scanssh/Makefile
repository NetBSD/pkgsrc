# $NetBSD: Makefile,v 1.40 2023/10/24 22:10:59 wiz Exp $

DISTNAME=	scanssh-2.1
PKGREVISION=	17
CATEGORIES=	security
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://monkey.org/~provos/scanssh/
COMMENT=	SSH remote version scanner
LICENSE=	original-bsd

GNU_CONFIGURE=		YES
USE_BUILTIN.libevent=	NO

.include "../../devel/libevent/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
