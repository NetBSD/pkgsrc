# $NetBSD: Makefile,v 1.1.1.1 2003/06/04 01:15:34 jschauma Exp $
#

DISTNAME=	abook-0.4.17
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=abook/}

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	http://abook.sourceforge.net/
COMMENT=	Text-based addressbook program

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
