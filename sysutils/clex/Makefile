# $NetBSD: Makefile,v 1.1.1.1 2005/12/01 03:54:26 minskim Exp $
#

DISTNAME=		clex-3.14
CATEGORIES=		sysutils
MASTER_SITES=		http://www.clex.sk/download/

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://www.clex.sk/download/
COMMENT=		File manager with a full-screen user interface

USE_NCURSES=		# enter_{bold,reverse,underline}_mode
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
