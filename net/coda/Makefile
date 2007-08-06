# $NetBSD: Makefile,v 1.5 2007/08/06 12:31:25 gdt Exp $
#

DISTNAME=	coda-6.9.2
CATEGORIES=	net
MASTER_SITES=	http://www.coda.cs.cmu.edu/pub/coda/src/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Coda distributed fileystem

# See http://coda.wikidev.net/Quick_Client_Action for hints on how
# to configure venus.

USE_TOOLS+=	gmake perl
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/lwp/buildlink3.mk"
.include "../../devel/rpc2/buildlink3.mk"
.include "../../devel/rvm/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
