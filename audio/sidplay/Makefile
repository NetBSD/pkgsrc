# $NetBSD: Makefile,v 1.8 2002/08/31 04:19:18 wiz Exp $
#

DISTNAME=	sidplay-base-1.0.4
PKGNAME=	sidplay-1.0.4
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	tools for playing sidtunes

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../audio/libsidplay/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
