# $NetBSD: Makefile,v 1.2 2005/12/07 12:21:04 mjl Exp $
#

PKGNAME=		asterisk-sounds-de-x9media-20051128
DISTNAME=		rita-voicefiles-ger-v2
CATEGORIES=		comms
MASTER_SITES=		http://www.asteriskfreaks.com/dcl/index.php?
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.asteriskfreaks.com/dcl/
COMMENT=		German voice prompt files for asterisk

FETCH_BEFORE_ARGS+=	-o ${DISTNAME}${EXTRACT_SUFX}

do-build:	# EMPTY

do-install:
	${MKDIR} ${LOCALBASE}/libdata/asterisk/sounds
	( cd ${WRKSRC}; ${TAR} -cf - . ) | ( cd ${LOCALBASE}/libdata/asterisk/sounds; ${TAR} -xf - )

.include "../../mk/bsd.pkg.mk"
