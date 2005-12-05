# $NetBSD: Makefile,v 1.10 2005/12/05 20:51:01 rillig Exp $
#

DISTNAME=	wtail-0.2.2
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.teaser.fr/~amajorel/wtail/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.teaser.fr/~amajorel/wtail/
COMMENT=	Watch multiple files at once


MAKE_ENV+=	SED=${SED:Q}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
