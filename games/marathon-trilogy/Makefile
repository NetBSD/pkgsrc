# $NetBSD: Makefile,v 1.4 2023/04/27 13:47:47 yhardy Exp $
#

# This number is rather arbitrary and only for pkgsrc's benefit.
DISTNAME=	marathon-trilogy-20230119
CATEGORIES=	games
DISTFILES=	Marathon-20230119-Data.zip Marathon2-20230119-Data.zip MarathonInfinity-20230119-Data.zip
MASTER_SITES+=	${MASTER_SITE_GITHUB:=Aleph-One-Marathon/}
EXTRACT_SUFX=	.zip
GITHUB_PROJECT=	alephone
GITHUB_RELEASE=	release-20230119

.for i in ${DISTFILES}
SITES.${i}=	${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_RELEASE}/}
.endfor

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	https://alephone.lhowon.org/
COMMENT=	Bungie game data files, playable with the Aleph One engine
LICENSE=	generic-nonlicense

# There is no true dependency on Aleph One.  These scenarios cannot be
# played without it, though.
#DEPENDS+=	alephone-[0-9]*:../../games/alephone

SCENARIO_BASE=		share/AlephOne/Scenarios
.for scenario in 1 2 Infinity
INSTALLATION_DIRS+=	${SCENARIO_BASE}/${scenario} ${SCENARIO_BASE}/${scenario}/Physics\ Models ${SCENARIO_BASE}/${scenario}/Scripts ${SCENARIO_BASE}/${scenario}/Themes ${SCENARIO_BASE}/${scenario}/Tracks
.endfor

NO_CONFIGURE=	yes
NO_BUILD=	yes

post-extract:
	${FIND} ${WRKDIR} -name CVS -print | ${XARGS} -I repl ${RM} -rf "repl"
	${FIND} ${WRKDIR}/Marathon -type f -exec ${CHMOD} 0644 {} \;
	${FIND} ${WRKDIR}/Marathon\ 2 -type f -exec ${CHMOD} 0644 {} \;
	${FIND} ${WRKDIR}/Marathon\ Infinity -type f -exec ${CHMOD} 0644 {} \;

do-install:
	#install the files into the Scenarios dir
	#there is no ${INSTALL_...} command with recursive abilities...
	${CP} -r ${WRKDIR}/Marathon/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/1
	${CP} -r ${WRKDIR}/Marathon\ 2/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/2
	${CP} -r ${WRKDIR}/Marathon\ Infinity/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Infinity

.include "../../mk/bsd.pkg.mk"
