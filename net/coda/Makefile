# $NetBSD: Makefile,v 1.6 2008/02/17 10:16:33 rillig Exp $
#

DISTNAME=	coda-6.9.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.coda.cs.cmu.edu/pub/coda/src/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Coda distributed fileystem

# See http://coda.wikidev.net/Quick_Client_Action for hints on how
# to configure venus.

USE_TOOLS+=	gmake perl perl:run
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
REPLACE_PERL=	coda-src/scripts/tape.pl coda-src/scripts/volmunge

.include "../../devel/lwp/buildlink3.mk"
.include "../../devel/rpc2/buildlink3.mk"
.include "../../devel/rvm/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
