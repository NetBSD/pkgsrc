# $NetBSD: Makefile,v 1.12 2004/01/22 07:15:00 grant Exp $
#

DISTNAME=	sidplay-base-1.0.9
PKGNAME=	sidplay-1.0.9
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@NetBSD.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	Tools for playing sidtunes

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../audio/libsidplay/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
