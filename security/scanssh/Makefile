# $NetBSD: Makefile,v 1.31 2011/02/11 21:22:04 tnn Exp $

DISTNAME=	scanssh-2.1
PKGREVISION=	11
CATEGORIES=	security
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~provos/scanssh/
COMMENT=	SSH remote version scanner

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_BUILTIN.libevent=	NO

.include "../../devel/libevent/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
