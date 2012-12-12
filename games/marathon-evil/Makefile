# $NetBSD: Makefile,v 1.1 2012/12/12 16:26:51 wiz Exp $

DISTNAME=	marathon-evil-199704
CATEGORIES=	games
MASTER_SITES=	http://files3.bungie.org/trilogy/
DISTFILES+=	MarathonEvil.zip
EXTRACT_SUFX=	.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://bighouse.bungie.org/evil/
COMMENT=	Game data for Marathon EVIL scenario, playable with Aleph One
LICENSE=	cc-by-nc-nd-v3.0-license

# There is no true dependency on Aleph One.  These scenarios cannot be
# played without it, though.
#DEPENDS+=	alephone-[0-9]*:../../games/alephone

.include "../../games/alephone/scenario.mk"
INSTALLATION_DIRS=	${SCENARIO_BASE}/Evil ${SCENARIO_BASE}/Evil/Scripts ${SCENARIO_BASE}/Evil/Themes
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

NO_CONFIGURE=	yes
NO_BUILD=	yes
MESSAGE_SUBST+=	SCENARIO_BASE="${SCENARIO_BASE}"

post-extract:
	#clean up irregular author packaging
	find -d ${WRKDIR} -name CVS -exec rm -rf {} \;
	find ${WRKDIR} -name .#* -exec rm -rf {} \;
	${CHMOD} 644 ${WRKDIR}/Marathon\ EVIL/Cursed*
	${CHMOD} 644 ${WRKDIR}/Marathon\ EVIL/Scripts/*
	${CHMOD} 644 ${WRKDIR}/Marathon\ EVIL/Themes/Default/*

do-install:
	#install the docs into doc dir and other files into the Scenarios dir
	#there is no ${INSTALL_...} command with recursive abilities...
	${INSTALL_DATA} ${WRKDIR}/Marathon\ EVIL/*.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${CP} -r ${WRKDIR}/Marathon\ EVIL/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Evil
	${RM} -f ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Evil/EVIL\ ReadMe.txt

.include "../../mk/bsd.pkg.mk"
