# $NetBSD: Makefile,v 1.20 2006/03/04 21:30:38 jlam Exp $

DISTNAME=	scanssh-2.1
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://monkey.org/~provos/				\
		ftp://ftp.openbsd.org/pub/OpenBSD/OpenSSH/scanssh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~provos/scanssh/
COMMENT=	SSH remote version scanner

GNU_CONFIGURE=		YES
USE_BUILTIN.libevent=	NO

.include "../../devel/libevent/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
