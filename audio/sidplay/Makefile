# $NetBSD: Makefile,v 1.7 2001/06/26 18:17:11 jlam Exp $
#

DISTNAME=	sidplay-base-1.0.4
PKGNAME=	sidplay-1.0.4
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	tools for playing sidtunes

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../audio/libsidplay/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
