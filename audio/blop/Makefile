# $NetBSD: Makefile,v 1.3 2012/09/11 23:59:26 asau Exp $
#

DISTNAME=	blop-0.2.8
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blop.sourceforge.net/
COMMENT=	Bandlimited LADSPA Oscillator Plugins
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-ladspa-prefix=${BUILDLINK_PREFIX.ladspa}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
