# $NetBSD: Makefile,v 1.20 2025/04/08 17:20:41 ryoon Exp $

DISTNAME=	gmime-3.2.15
PKGNAME=	${DISTNAME:S/gmime/gmime3/}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=jstedfast/}
GITHUB_PROJECT=	gmime
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spruce.sourceforge.net/gmime/
COMMENT=	Library for the creation and parsing of MIME messages (API v3)
LICENSE=	gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk-doc=no
PKGCONFIG_OVERRIDE+=	gmime.pc.in

CPPFLAGS+=		-DGPGRT_ENABLE_ES_MACROS

# one test failure as of 3.2.6
# test-filters:
# https://github.com/jstedfast/gmime/issues/81
TEST_TARGET=		check

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
