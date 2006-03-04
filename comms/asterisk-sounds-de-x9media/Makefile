# $NetBSD: Makefile,v 1.4 2006/03/04 21:29:04 jlam Exp $
#

PKGNAME=		asterisk-sounds-de-x9media-20060114
DISTNAME=		rita-voicefiles-ger-v3
CATEGORIES=		comms
MASTER_SITES=		http://www.asteriskfreaks.com/dcl/index.php?
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.asteriskfreaks.com/dcl/
COMMENT=		German voice prompt files for asterisk

FETCH_BEFORE_ARGS+=	-o ${DISTNAME}${EXTRACT_SUFX}

do-build:	# EMPTY

do-install:
	${MKDIR} ${LOCALBASE}/libdata/asterisk/sounds
	( cd ${WRKSRC}; ${TAR} -cf - . ) | ( cd ${LOCALBASE}/libdata/asterisk/sounds; ${TAR} -xf - )

.include "../../mk/bsd.pkg.mk"
