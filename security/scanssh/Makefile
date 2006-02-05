# $NetBSD: Makefile,v 1.19 2006/02/05 23:10:47 joerg Exp $

DISTNAME=	scanssh-2.1
PKGREVISION=	2
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
