# $NetBSD: Makefile,v 1.18 2001/11/17 16:29:07 martin Exp $

DISTNAME=	festival-1.4.1
WRKSRC=		${WRKDIR}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.1/ \
		http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/ \
		ftp://cslu.cse.ogi.edu/pub/tts/
DISTFILES=	${DISTNAME}.tar.gz \
		speech_tools-1.2.1.tar.gz \
		OGIresLPC-2.0.9.tar.gz \
		OGIfestpatch-1.4.1.2.tar.gz
# note that OGIfestpatch above file must be extracted last. it is, however
# this behavior not defined in pkgsrc at the time of writing

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html
COMMENT=	Festival is an advanced multi-lingual speech synthesis system

USE_GMAKE=	yes

SPEECHTOOLS=	${WRKSRC}/speech_tools
FESTIVAL=	${WRKSRC}/festival

FHOME=		${PREFIX}/share/festival

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	PKG_EST_HOME="${SPEECHTOOLS}"				\
		EST_HOME="${SPEECHTOOLS}"				\
		PKG_FESTIVAL_BUILD_HOME="${FESTIVAL}"			\
		PKG_FESTIVAL_HOME="${FHOME}"				\
		PKG_COMPILER="${PKG_COMPILER}"				\
		PKG_X11BASE="${X11BASE}"				\
		PKG_PREFIX="${PREFIX}"					\
		EGCS_CC="${CC}"						\
		EGCS_CXX="${CXX}"					\
		GCC295_CC="${CC}"					\
		GCC295_CXX="${CXX}"					\
		GCC28_CC="${CC}"					\
		GCC28_CXX="${CXX}"					\
		GCC27_CC="${CC}"					\
		GCC27_CXX="${CXX}"					\
		GCC26_CC="${CC}"					\
		GCC26_CXX="${CXX}"					\
		CC="${CC}"						\
		CXX="${CXX}"

pre-patch:
	@ ${CP} ${SPEECHTOOLS}/config/config-dist ${SPEECHTOOLS}/config/config && \
	  ${CHMOD} u+w ${SPEECHTOOLS}/config/config
	@ ${CP} ${FESTIVAL}/config/config-dist ${FESTIVAL}/config/config && \
	  ${CHMOD} u+w ${FESTIVAL}/config/config

post-patch:
	@ ${CP} ${FILESDIR}/top-Makefile ${WRKSRC}/Makefile
	@ ${CP} ${FILESDIR}/NetBSD.mak ${SPEECHTOOLS}/config/systems/NetBSD.mak

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	${CHMOD} -R u+w,a+r,og-w ${FESTIVAL}/lib
	${FIND} ${FESTIVAL}/lib -type d -print | ${XARGS} ${CHMOD} 755
	cd ${FESTIVAL} && ${PAX} -r -w lib examples ${FHOME}
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

.include "../../audio/nas/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

# has to be below bsd.pkg.mk, else ${ECHO} isn't expanded correctly
PKG_COMPILER!=	case "`${CC} -v 2>&1`" in *2.6.*) ${ECHO} gcc26;;\
                                          *2.7.*) ${ECHO} gcc27;;\
                                          *2.8.*) ${ECHO} gcc28;;\
					  *2.95.*) ${ECHO} gcc295;;\
                                          *egcs*) ${ECHO} egcs;;\
                                       esac
