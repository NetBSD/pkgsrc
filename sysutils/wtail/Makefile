# $NetBSD: Makefile,v 1.4 2003/09/27 17:07:38 grant Exp $
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

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
