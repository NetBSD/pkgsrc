# $NetBSD: Makefile,v 1.1.1.1 2001/03/13 13:18:24 wiz Exp $
#

DISTNAME=		unofficial-csound-4.09.0.0b-linux.src
PKGNAME=		csound-4.09
CATEGORIES=		audio
MASTER_SITES=		ftp://mustec.bgsu.edu/pub/linux/

MAINTAINER=		collver@softhome.net
HOMEPAGE=		http://www.csound.org
COMMENT=		software synthesizer and sequencer

BUILD_DEPENDS+=         ${LOCALBASE}/bin/autoreconf:../../devel/autoconf

LICENSE=		csound-license
NO_SRC_ON_CDROM=	"no for-fee-redistribution"
NO_BIN_ON_CDROM=	${NO_SRC_ON_CDROM}

DIST_SUBDIR=		csound
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-x --enable-OSS-RTAUDIO
CONFLICTS=		csound-bath*

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf --force

.include "../../mk/bsd.pkg.mk"
