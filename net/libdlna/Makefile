# $NetBSD: Makefile,v 1.17 2020/04/23 15:24:00 nia Exp $

DISTNAME=	libdlna-0.2.4
PKGREVISION=	9
CATEGORIES=	net
MASTER_SITES=	http://libdlna.geexbox.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libdlna.geexbox.org/
COMMENT=	Reference DLNA open-source implementation
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c
HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE=		libdlna.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-ffmpeg-dir=${BUILDLINK_PREFIX.ffmpeg}

MAKE_JOBS_SAFE=		no

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	configure
SUBST_SED.config=	-e 's,/usr/bin/install,${INSTALL},'

.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
