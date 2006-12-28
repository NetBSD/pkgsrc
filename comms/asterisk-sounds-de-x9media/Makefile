# $NetBSD: Makefile,v 1.5 2006/12/28 12:01:38 mjl Exp $
#

PKGNAME=		asterisk-sounds-de-x9media-20060714
DISTNAME=		asterisk-x9rita-soundfiles-ger-v4
CATEGORIES=		comms
MASTER_SITES=		http://www.x9media.com/downloads/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.x9media.com/
COMMENT=		German voice prompt files for asterisk

FETCH_BEFORE_ARGS+=	-o ${DISTNAME}${EXTRACT_SUFX}

do-build:	# EMPTY

do-install:
	${MKDIR} ${LOCALBASE}/libdata/asterisk/sounds
	( cd ${WRKSRC}; tar -cf - de digits ) | ( cd ${LOCALBASE}/libdata/asterisk/sounds; tar -xf - )
	( cd ${WRKSRC}/x9media; tar -cf - . ) | ( cd ${LOCALBASE}/libdata/asterisk/sounds/de; tar -xf - )

.include "../../mk/bsd.pkg.mk"
