# $NetBSD: Makefile,v 1.32 2019/11/10 11:27:07 nia Exp $

DISTNAME=		mpc-0.33
CATEGORIES=		audio
MASTER_SITES=		http://www.musicpd.org/download/mpc/0/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Command-line client for musicpd
LICENSE=		gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

REPLACE_SH=		doc/*.sh

LDFLAGS+=		${BUILDLINK_LDADD.iconv}

# By default it generates and installs HTML documentation if py-sphinx
# is installed, causing our PLIST check to fail.
MESON_ARGS+=		-Ddocumentation=disabled

.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.libmpdclient+=	libmpdclient>=2.9
.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
