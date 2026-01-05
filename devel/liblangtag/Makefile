# $NetBSD: Makefile,v 1.34 2026/01/05 09:07:56 wiz Exp $

DISTNAME=	liblangtag-0.6.7
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/tagoh/liblangtag/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/tagoh/liblangtag
COMMENT=	RFC 5646 language tag interface library
LICENSE=	gnu-lgpl-v3 OR mpl-2.0

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c
PKGCONFIG_OVERRIDE+=	liblangtag.pc.in

#TEST_TARGET=	check
#.include "../../devel/check/buildlink3.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
