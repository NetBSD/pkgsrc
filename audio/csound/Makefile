# $NetBSD: Makefile,v 1.7 2002/03/23 02:36:45 wiz Exp $
#

DISTNAME=		unofficial-csound-4.13.0.2a-linux.src
PKGNAME=		csound-4.13.0.2a
CATEGORIES=		audio
MASTER_SITES=		ftp://mustec.bgsu.edu/pub/linux/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.csound.org
COMMENT=		software synthesizer and sequencer

LICENSE=		csound-license
RESTRICTED=		"no for-fee-redistribution"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DIST_SUBDIR=		csound
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-x --enable-rtaudio=netbsd
CONFLICTS=		csound-bath*

pre-configure:
	${CP} ${FILESDIR}/rtNetBSD.h ${FILESDIR}/rtNetBSD.c ${WRKSRC}/new-src/

.include "../../mk/bsd.pkg.mk"
