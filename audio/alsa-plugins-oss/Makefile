# $NetBSD: Makefile,v 1.2 2008/12/19 12:34:22 jmcneill Exp $
#

DISTNAME=	alsa-plugins-1.0.18
PKGNAME=	${DISTNAME:S/plugins/plugins-oss/}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture (ALSA) - OSS plugin

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config gmake
USE_LIBTOOL=	yes

CFLAGS+=	-DDEVOSSAUDIO=\"${DEVOSSAUDIO:U/dev/dsp}\"
LIBS+=		${LIBOSSAUDIO}

do-build:
	cd ${WRKSRC}/oss && ${GMAKE}

do-install:
	cd ${WRKSRC}/oss && ${GMAKE} install

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
