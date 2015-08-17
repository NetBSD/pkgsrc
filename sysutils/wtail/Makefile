# $NetBSD: Makefile,v 1.14 2015/08/17 17:11:29 wiz Exp $
#

DISTNAME=	wtail-0.2.2
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.teaser.fr/~amajorel/wtail/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.teaser.fr/~amajorel/wtail/
COMMENT=	Watch multiple files at once

MAKE_ENV+=	SED=${SED:Q}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
