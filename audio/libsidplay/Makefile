# $NetBSD: Makefile,v 1.10 2002/11/23 18:36:30 pooka Exp $
#

DISTNAME=	libsidplay-1.36.57
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	Sidplay Library

CONFLICTS=	sidplay-1.36.*

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig

.include "../../mk/bsd.pkg.mk"
