# $NetBSD: Makefile,v 1.25 2018/02/25 20:30:21 wiz Exp $

DISTNAME=		mpc-0.29
CATEGORIES=		audio
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=musicpd/}
MASTER_SITES=		http://www.musicpd.org/download/mpc/0/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Command-line client for musicpd
LICENSE=		gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

REPLACE_SH=		doc/*.sh

LIBS+=			${BUILDLINK_LDADD.iconv}

.include "../../devel/py-meson/build.mk"
BUILDLINK_API_DEPENDS.libmpdclient+=	libmpdclient>=2.9
.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
