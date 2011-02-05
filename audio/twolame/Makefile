# $NetBSD: Makefile,v 1.7 2011/02/05 13:32:44 ryoon Exp $
#

DISTNAME=	twolame-0.3.13
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=twolame/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.twolame.org/
COMMENT=	Optimised MPEG Audio Layer 2 (MP2) encoder based on tooLAME

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	twolame.pc.in

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
