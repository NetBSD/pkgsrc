# $NetBSD: Makefile,v 1.38 2005/04/28 22:21:52 jlam Exp $

DISTNAME=	festival-1.95-beta
PKGNAME=	festival-1.95beta
CATEGORIES=	audio
MASTER_SITES=	http://festvox.org/packed/festival/1.95/ \
		ftp://cslu.cse.ogi.edu/pub/tts/
DISTFILES=	${DISTNAME}.tar.gz \
		speech_tools-1.2.95-beta.tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival/
COMMENT=	Advanced multi-lingual speech synthesis system

WRKSRC=		${WRKDIR}
USE_GNU_TOOLS+=	make
USE_X11=	yes

SPEECHTOOLS=	${WRKSRC}/speech_tools
FESTIVAL=	${WRKSRC}/festival

FHOME=		${PREFIX}/share/festival

CONFIG_GUESS_OVERRIDE=	${SPEECHTOOLS}/config.guess ${FESTIVAL}/config.guess
CONFIG_SUB_OVERRIDE=	${SPEECHTOOLS}/config.sub ${FESTIVAL}/config.sub

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
PKG_COMPILER?=		suncc
.else
PKG_COMPILER_cmd=	case "${CC_VERSION}" in				\
			gcc-2.6.*)	${ECHO} gcc26;;			\
			gcc-2.7.*)	${ECHO} gcc27;;			\
			gcc-2.8.*)	${ECHO} gcc28;;			\
			gcc-2.95.*)	${ECHO} gcc295;;		\
			gcc-3.3.*)	${ECHO} gcc32;;			\
			egcs*)		${ECHO} egcs;;			\
			*)		${ECHO} ;;			\
			esac
PKG_COMPILER=		${PKG_COMPILER_cmd:sh}
.endif

.if empty(PKG_COMPILER)
PKG_FAIL_REASON=	"${CC_VERSION} is not currently supported."
.endif

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

post-patch:
	@${CP} ${FILESDIR}/top-Makefile ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/unknown_${OPSYS}.mak ${SPEECHTOOLS}/config/systems/unknown_${OPSYS}.mak
	@${CP} ${FILESDIR}/unknown_${OPSYS}.mak ${FESTIVAL}/config/systems/unknown_${OPSYS}.mak

do-configure:
	cd ${SPEECHTOOLS} && ${ENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	${CHMOD} -R u+w,a+r,og-w ${FESTIVAL}/lib
	${FIND} ${FESTIVAL}/lib -type d -print | ${XARGS} ${CHMOD} 755
	-@${MV} ${FESTIVAL}/lib/etc/unknown_${OPSYS} ${FESTIVAL}/lib/etc/pkgsrc
	cd ${FESTIVAL} && ${PAX} -rw lib examples ${FHOME}
	${RM} -f ${FHOME}/lib/etc/unknown_${OPSYS}/audsp ${FHOME}/lib/etc/pkgsrc/audsp
	${INSTALL_PROGRAM} ${FESTIVAL}/lib/etc/pkgsrc/audsp ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival ${PREFIX}/libexec/festival.naked
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival_client ${PREFIX}/libexec/festival_client.naked
	for n in festival.sh festival_client.sh sitevars.scm; do	\
		${SED} "s%@PKG_FESTIVAL_LOCATION@%${FHOME}%;		\
			s%@PKG_PREFIX@%${PREFIX}%" <${FILESDIR}/$$n > ${WRKDIR}/$$n ; \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/festival.sh ${PREFIX}/bin/festival
	${INSTALL_SCRIPT} ${WRKDIR}/festival_client.sh ${PREFIX}/bin/festival_client
	${INSTALL_DATA} ${WRKDIR}/sitevars.scm ${FHOME}/lib/sitevars.scm
	${INSTALL_MAN} ${FESTIVAL}/doc/festival.1 ${PREFIX}/man/man1/festival.1
	${INSTALL_MAN} ${FESTIVAL}/doc/festival_client.1 ${PREFIX}/man/man1/festival_client.1

.include "../../audio/nas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
