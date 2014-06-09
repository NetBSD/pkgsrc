# $NetBSD: Makefile,v 1.16 2014/06/09 12:42:58 ryoon Exp $
#

DISTNAME=	alsa-plugins-1.0.27
PKGNAME=	${DISTNAME:S/plugins/plugins-pulse/}
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
