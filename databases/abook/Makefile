# $NetBSD: Makefile,v 1.5 2003/09/28 09:13:56 jlam Exp $
#

DISTNAME=	abook-0.5.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=abook/}

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	http://abook.sourceforge.net/
COMMENT=	Text-based addressbook program

USE_BUILDLINK2=		yes
USE_GNU_READLINE=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
