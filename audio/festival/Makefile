# $NetBSD: Makefile,v 1.1.1.1 1999/04/04 19:32:33 proff Exp $

DISTNAME=	festival-1.3.1
WRKSRC=		${WRKDIR}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.3.1/ \
		ftp://cslu.cse.ogi.edu/pub/tts/
DISTFILES=	${DISTNAME}.tar.gz \
		speech_tools-1.1.1.tar.gz \
		OGIresLPC-1.4.tar.gz

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

DEPENDS+=	nas-1.2.5:../nas

USE_GMAKE=	yes

SPEECHTOOLS=	${WRKSRC}/speech_tools
FESTIVAL=	${WRKSRC}/festival

FHOME=		${PREFIX}/share/festival

PKG_COMPILER!=	case "`${CC} -v 2>&1`" in *2.6.*) echo gcc26;;\
                                          *2.7.*) echo gcc27;;\
                                          *2.8.*) echo gcc28;;\
                                          *egcs*) echo egcs;;\
                                       esac

MAKE_ENV+=	PKG_EST_HOME=${SPEECHTOOLS} \
		PKG_FESTIVAL_HOME=${FESTIVAL} \
		PKG_COMPILER=${PKG_COMPILER} \
		PKG_X11BASE=${X11BASE} \
		PKG_PREFIX=${PREFIX} \
		EGCS_CC=${CC} \
		EGCS_CXX=${CXX} \
		GCC28_CC=${CC} \
		GCC28_CXX=${CXX} \
		GCC27_CC=${CC} \
		GCC27_CXX=${CXX} \
		GCC26_CC=${CC} \
		GCC26_CXX=${CXX} \
		CC=${CC} \
		CXX=${CXX}

pre-patch:
	@ ${CP} ${SPEECHTOOLS}/config/config-dist ${SPEECHTOOLS}/config/config && \
	  chmod u+w ${SPEECHTOOLS}/config/config
	@ ${CP} ${FESTIVAL}/config/config-dist ${FESTIVAL}/config/config && \
	  chmod u+w ${FESTIVAL}/config/config

post-patch:
	@ ${CP} ${FILESDIR}/top-Makefile ${WRKSRC}/Makefile
	@ ${CP} ${FILESDIR}/NetBSD.mak ${SPEECHTOOLS}/config/systems/NetBSD.mak

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	chmod -R u+w,a+r,og-w ${FESTIVAL}/lib
	find ${FESTIVAL}/lib -type d -print0| xargs -0 chmod a+x
	cd ${FESTIVAL} && pax -r -w lib examples ${FHOME}
	${RM} -f ${FHOME}/lib/etc/NetBSD/audsp
	${INSTALL_PROGRAM} ${FESTIVAL}/lib/etc/NetBSD/audsp ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival ${PREFIX}/libexec/festival.naked
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival_client ${PREFIX}/libexec/festival_client.naked
	for n in festival.sh festival_client.sh sitevars.scm; \
	do {\
	  ${SED} "s%@PKG_FESTIVAL_LOCATION@%${FHOME}%; \
	       s%@PKG_PREFIX@%${PREFIX}%" <${FILESDIR}/$$n > ${WRKDIR}/$$n ;} \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/festival.sh ${PREFIX}/bin/festival
	${INSTALL_SCRIPT} ${WRKDIR}/festival_client.sh ${PREFIX}/bin/festival_client
	${INSTALL_DATA} ${WRKDIR}/sitevars.scm ${FHOME}/lib/sitevars.scm
	${INSTALL_MAN} ${FESTIVAL}/doc/festival.1 ${PREFIX}/man/man1/festival.1
	${INSTALL_MAN} ${FESTIVAL}/doc/festival_client.1 ${PREFIX}/man/man1/festival_client.1

.include "../../mk/bsd.pkg.mk"
