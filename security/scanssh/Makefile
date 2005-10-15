# $NetBSD: Makefile,v 1.18 2005/10/15 06:55:38 rillig Exp $

DISTNAME=	scanssh-2.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://monkey.org/~provos/				\
		ftp://ftp.openbsd.org/pub/OpenBSD/OpenSSH/scanssh/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://monkey.org/~provos/scanssh/
COMMENT=	SSH remote version scanner

GNU_CONFIGURE=		YES
USE_BUILTIN.libevent=	NO

.include "../../devel/libevent/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
