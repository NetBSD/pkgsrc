# $NetBSD: Makefile,v 1.1.1.1 2006/05/21 10:16:55 xtraeme Exp $
#

DISTNAME=	twolame-0.3.7
CATEGORIES=	audio
MASTER_SITES=	http://www.ecs.soton.ac.uk/~njh/twolame/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.twolame.org/
COMMENT=	Optimised MPEG Audio Layer 2 (MP2) encoder based on tooLAME

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	twolame.pc.in

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
