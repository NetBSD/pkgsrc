# $NetBSD: Makefile,v 1.13 2013/11/25 12:00:46 wiz Exp $
#

DISTNAME=	alsa-plugins-1.0.22
PKGNAME=	${DISTNAME:S/plugins/plugins-pulse/}
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture (ALSA) - PulseAudio plugin

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config gmake
USE_LIBTOOL=	yes

BUILD_DIRS=	pulse

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
