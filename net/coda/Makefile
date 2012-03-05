# $NetBSD: Makefile,v 1.11 2012/03/05 11:27:52 gdt Exp $
#

DISTNAME=	coda-6.9.5
PKGEREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.coda.cs.cmu.edu/pub/coda/src/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Coda distributed fileystem

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# See http://coda.wikidev.net/Quick_Client_Action for hints on how
# to configure venus.

USE_TOOLS+=	gmake pkg-config perl perl:run
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
REPLACE_PERL=	coda-src/scripts/tape.pl coda-src/scripts/volmunge

.include "../../devel/lwp/buildlink3.mk"
.include "../../devel/rpc2/buildlink3.mk"
.include "../../devel/rvm/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
