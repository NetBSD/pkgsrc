# $NetBSD: Makefile,v 1.3 2003/08/28 20:05:21 xtraeme Exp $
#

DISTNAME=	wtail-0.2.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.teaser.fr/~amajorel/wtail/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.teaser.fr/~amajorel/wtail/
COMMENT=	Watch multiple files at once

USE_BUILDLINK2=	YES

MAKE_ENV+=	SED="${SED}"

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
