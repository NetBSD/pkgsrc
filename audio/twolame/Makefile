# $NetBSD: Makefile,v 1.15 2025/02/12 06:44:31 ryoon Exp $

DISTNAME=	twolame-0.4.0
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=twolame/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.twolame.org/
COMMENT=	Optimised MPEG Audio Layer 2 (MP2) encoder based on tooLAME
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	twolame.pc.in

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
