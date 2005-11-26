# $NetBSD: Makefile,v 1.1.1.1 2005/11/26 01:41:59 mjl Exp $
#

PKGNAME=		asterisk-sounds-de-x9media-20051126
DISTNAME=		rita-voicefiles-ger
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
