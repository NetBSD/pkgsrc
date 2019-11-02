# $NetBSD: Makefile,v 1.17 2019/11/02 15:38:08 rillig Exp $
#

DISTNAME=	pxtools-0.0.20
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://jan.kneschke.de/projects/pxtools/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jan.kneschke.de/projects/pxtools/
COMMENT=		Paradox database export/info utilities

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake

GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
