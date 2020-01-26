# $NetBSD: Makefile,v 1.5 2020/01/26 05:26:09 rillig Exp $
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
