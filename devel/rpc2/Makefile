# $NetBSD: Makefile,v 1.26 2007/04/11 18:14:17 gdt Exp $
#

DISTNAME=	rpc2-2.5
CATEGORIES=	devel
MASTER_SITES=	http://www.coda.cs.cmu.edu/pub/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	CMU (Coda) remote procedure call package

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/lwp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
