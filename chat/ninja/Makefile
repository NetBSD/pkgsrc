# $NetBSD: Makefile,v 1.19 2026/02/16 04:14:38 jnemeth Exp $
#

DISTNAME=	ninja-1.5.8.1
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	ftp://qoop.org/ninja/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://qoop.org/ninja/
COMMENT=	Another IRC client based on ircII

CONFLICTS+=	ninja-build-[0-9]*

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

.include "options.mk"

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
