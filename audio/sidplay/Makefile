# $NetBSD: Makefile,v 1.15 2005/04/11 21:44:56 tv Exp $
#

DISTNAME=	sidplay-base-1.0.9
PKGNAME=	sidplay-1.0.9
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@NetBSD.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	Tools for playing sidtunes

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
