# $NetBSD: Makefile,v 1.2 2003/07/13 13:53:24 wiz Exp $
#

DISTNAME=	wtail-0.2.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.teaser.fr/~amajorel/wtail/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.teaser.fr/~amajorel/wtail/
COMMENT=	Watch multiple files at once

USE_BUILDLINK2=	YES

MAKE_ENV+=	SED="${SED}"

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
