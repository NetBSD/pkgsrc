# $NetBSD: Makefile,v 1.18 2006/02/05 23:08:13 joerg Exp $
#

DISTNAME=	sidplay-base-1.0.9
PKGNAME=	sidplay-1.0.9
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@NetBSD.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	Tools for playing sidtunes

NOT_FOR_PLATFORM=	Interix-*-*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
