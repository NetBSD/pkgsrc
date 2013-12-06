# $NetBSD: Makefile,v 1.20 2013/12/06 13:39:34 wiz Exp $

DISTNAME=		mpc-0.25
CATEGORIES=		audio
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=musicpd/}
MASTER_SITES=		http://www.musicpd.org/download/mpc/0/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Command-line client for musicpd
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

REPLACE_SH=		doc/*.sh

LIBS.SunOS+=		${BUILDLINK_LDADD.iconv}

.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
