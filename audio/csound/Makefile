# $NetBSD: Makefile,v 1.4 2001/08/27 14:35:05 tron Exp $
#

DISTNAME=		unofficial-csound-4.12.0.1b-linux.src
PKGNAME=		csound-4.12
CATEGORIES=		audio
MASTER_SITES=		ftp://mustec.bgsu.edu/pub/linux/

MAINTAINER=		collver@softhome.net
HOMEPAGE=		http://www.csound.org
COMMENT=		software synthesizer and sequencer

BUILD_DEPENDS+=         autoconf>=2.13:../../devel/autoconf

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
