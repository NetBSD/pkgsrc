# $NetBSD: Makefile,v 1.9 2004/07/28 02:50:22 kim Exp $
#

DISTNAME=	abook-0.5.2
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=abook/}

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	http://abook.sourceforge.net/
COMMENT=	Text-based addressbook program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_READLINE=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
