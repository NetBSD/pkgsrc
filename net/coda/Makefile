# $NetBSD: Makefile,v 1.2 2007/04/15 14:03:50 gdt Exp $
#

DISTNAME=	coda-6.9.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.coda.cs.cmu.edu/pub/coda/src/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Coda distributed fileystem

# Top-level Makefile is missing .WAIT, reported upstream 20070412 by gdt.
MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gmake perl
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

INSTALL_TARGET=	client-install server-install

.include "../../devel/lwp/buildlink3.mk"
.include "../../devel/rpc2/buildlink3.mk"
.include "../../devel/rvm/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
