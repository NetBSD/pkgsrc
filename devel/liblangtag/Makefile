# $NetBSD: Makefile,v 1.38 2026/09/27 11:35:42 tnn Exp $

DISTNAME=	liblangtag-0.6.8
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/tagoh/liblangtag/-/releases/${PKGVERSION_NOREV}/downloads/
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
