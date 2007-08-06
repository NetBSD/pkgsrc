# $NetBSD: Makefile,v 1.30 2007/08/06 13:09:13 gdt Exp $
#

DISTNAME=	rpc2-2.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.coda.cs.cmu.edu/pub/rpc2/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	CMU (Coda) remote procedure call package

USE_TOOLS+=		gmake perl
# Right now yacc is not actually used, just checked for.
USE_TOOLS+=		yacc

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/lwp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
