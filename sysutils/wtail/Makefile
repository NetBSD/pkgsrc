# $NetBSD: Makefile,v 1.7 2004/05/07 01:14:50 xtraeme Exp $
#

DISTNAME=	wtail-0.2.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.teaser.fr/~amajorel/wtail/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.teaser.fr/~amajorel/wtail/
COMMENT=	Watch multiple files at once

USE_BUILDLINK3=	YES

MAKE_ENV+=	SED="${SED}"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
