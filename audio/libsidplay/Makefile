# $NetBSD: Makefile,v 1.7 2001/12/24 15:13:31 mycroft Exp $
#

DISTNAME=	libsidplay-1.36.47
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	Sidplay Library

CONFLICTS=	sidplay-1.36.*

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BUILDLINK_ONLY=	yes

USE_LIBTOOL=		yes
LDFLAGS+=		-lstdc++ -lm
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig

.include "../../mk/bsd.pkg.mk"
