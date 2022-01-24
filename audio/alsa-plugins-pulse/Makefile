# $NetBSD: Makefile,v 1.36 2022/01/24 10:10:49 wiz Exp $

DISTNAME=	alsa-plugins-1.2.6
PKGNAME=	${DISTNAME:S/plugins/plugins-pulse/}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture (ALSA) - PulseAudio plugin
LICENSE=	gnu-lgpl-v2.1 OR gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config gmake
USE_LIBTOOL=	yes

BUILD_DIRS=	pulse

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
