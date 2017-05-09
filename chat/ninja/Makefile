# $NetBSD: Makefile,v 1.18 2017/05/09 14:53:26 jperkin Exp $
#

DISTNAME=	ninja-1.5.8.1
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	ftp://qoop.org/ninja/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://qoop.org/ninja/
COMMENT=	Another IRC client based on ircII

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

.include "options.mk"

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
