# $NetBSD: Makefile,v 1.5 2001/02/16 13:30:49 wiz Exp $
#

DISTNAME=	sidplay-base-1_0_4
PKGNAME=	sidplay-1.0.4
WRKSRC=		${WRKDIR}/sidplay-base-1.0.4
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	tools for playing sidtunes

DEPENDS+=	libsidplay>=1.36.38:../../audio/libsidplay

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+= --with-sidplay-includes=${LOCALBASE}/include \
		--with-sidplay-library=${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
