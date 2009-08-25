# $NetBSD: Makefile,v 1.8 2009/08/25 11:56:34 wiz Exp $
#

PKGNAME=		asterisk-sounds-de-x9media-20060714
PKGREVISION=		1
DISTNAME=		asterisk-x9rita-soundfiles-ger-v4
CATEGORIES=		comms
MASTER_SITES=		http://www.x9media.com/downloads/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.x9media.com/
COMMENT=		German voice prompt files for asterisk

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		tar

FETCH_BEFORE_ARGS+=	-o ${DISTNAME}${EXTRACT_SUFX}

do-build:	# EMPTY

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/libdata/asterisk/sounds
	( cd ${WRKSRC}; tar -cf - de digits ) | ( cd ${DESTDIR}${PREFIX}/libdata/asterisk/sounds; tar -xf - )
	( cd ${WRKSRC}/x9media; tar -cf - . ) | ( cd ${DESTDIR}${PREFIX}/libdata/asterisk/sounds/de; tar -xf - )

.include "../../mk/bsd.pkg.mk"
