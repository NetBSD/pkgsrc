# $NetBSD: Makefile,v 1.5 2002/01/11 14:50:31 skrll Exp $
#

DISTNAME=		unofficial-csound-4.12.0.1b-linux.src
PKGNAME=		csound-4.12
CATEGORIES=		audio
MASTER_SITES=		ftp://mustec.bgsu.edu/pub/linux/

MAINTAINER=		collver@softhome.net
HOMEPAGE=		http://www.csound.org
COMMENT=		software synthesizer and sequencer

LICENSE=		csound-license
NO_SRC_ON_CDROM=	"no for-fee-redistribution"
NO_BIN_ON_CDROM=	${NO_SRC_ON_CDROM}

DIST_SUBDIR=		csound
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-x --enable-OSS-RTAUDIO
CONFLICTS=		csound-bath*

.include "../../mk/bsd.pkg.mk"
