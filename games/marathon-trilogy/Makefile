# $NetBSD: Makefile,v 1.1.1.1 2010/02/03 11:19:12 wiz Exp $
#

# This number is rather arbitrary and only for pkgsrc's benefit.
DISTNAME=	marathon-trilogy-1.0
CATEGORIES=	games
# The original Bungie trilogy series
DISTFILES=	M1A1.zip Marathon2.zip MarathonInfinity.zip
MASTER_SITES=	http://trilogyrelease.bungie.org/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://trilogyrelease.bungie.org/
COMMENT=	Bungie game data files, playable with the Aleph One engine
LICENSE=	generic-nonlicense

# There is no true dependency on Aleph One.  These scenarios cannot be
# played without it, though.
#DEPENDS+=	alephone-[0-9]*:../../games/alephone

PKG_DESTDIR_SUPPORT=	user-destdir

SCENARIO_BASE=		share/AlephOne/Scenarios
.for scenario in 1 2 Infinity
INSTALLATION_DIRS+= ${SCENARIO_BASE}/${scenario} ${SCENARIO_BASE}/${scenario}/Physics\ Models ${SCENARIO_BASE}/${scenario}/Scripts ${SCENARIO_BASE}/${scenario}/Themes ${SCENARIO_BASE}/${scenario}/Tracks
.endfor

NO_CONFIGURE=	yes
NO_BUILD=	yes

post-extract:
	${FIND} ${WRKDIR} -name CVS -print | ${XARGS} -I repl ${RM} -rf "repl"
	${FIND} ${WRKDIR}/M1A1 -type f -exec ${CHMOD} 0644 {} \;
	${FIND} ${WRKDIR}/Marathon\ 2 -type f -exec ${CHMOD} 0644 {} \;
	${FIND} ${WRKDIR}/Marathon\ Infinity -type f -exec ${CHMOD} 0644 {} \;

do-install:
	#install the files into the Scenarios dir
	#there is no ${INSTALL_...} command with recursive abilities...
	${CP} -r ${WRKDIR}/M1A1/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/1
	${CP} -r ${WRKDIR}/Marathon\ 2/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/2
	${CP} -r ${WRKDIR}/Marathon\ Infinity/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Infinity

.include "../../mk/bsd.pkg.mk"
