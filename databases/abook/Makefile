# $NetBSD: Makefile,v 1.12 2004/11/29 01:39:17 minskim Exp $
#

DISTNAME=	abook-0.5.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=abook/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://abook.sourceforge.net/
COMMENT=	Text-based addressbook program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_READLINE=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
