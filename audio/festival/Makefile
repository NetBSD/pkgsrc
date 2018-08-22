# $NetBSD: Makefile,v 1.76 2018/08/22 09:42:54 wiz Exp $

DISTNAME=	festival-2.1-release
PKGNAME=	festival-2.1
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://festvox.org/packed/festival/2.1/
DISTFILES=	${DISTNAME}.tar.gz \
		speech_tools-2.1-release.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival/
COMMENT=	Advanced multi-lingual speech synthesis system
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++03
USE_TOOLS+=	gmake pax perl
MAKE_JOBS_SAFE=	no
REPLACE_PERL=	festival/examples/festival_client.pl

SPEECHTOOLS=	${WRKSRC}/speech_tools
FESTIVAL=	${WRKSRC}/festival
FHOME=		${PREFIX}/share/festival

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${SPEECHTOOLS}/configure
CONFIG_GUESS_OVERRIDE=	${SPEECHTOOLS}/config.guess ${FESTIVAL}/config.guess
CONFIG_SUB_OVERRIDE=	${SPEECHTOOLS}/config.sub ${FESTIVAL}/config.sub

MAKE_ENV+=	BUILDLINK_CPPFLAGS=${BUILDLINK_CPPFLAGS:Q}
MAKE_ENV+=	BUILDLINK_LDFLAGS=${BUILDLINK_LDFLAGS:Q}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
PKG_COMPILER?=		suncc
.else
PKG_COMPILER_cmd=	case "${CC_VERSION}" in				\
			gcc-2.7.*)	${ECHO} gcc27;;			\
			gcc-2.8.*)	${ECHO} gcc28;;			\
			gcc-2.95.*)	${ECHO} gcc295;;		\
			gcc-2.96.*)	${ECHO} gcc296;;		\
			gcc-3.0.*)	${ECHO} gcc30;;			\
			gcc-3.1.*)	${ECHO} gcc31;;			\
			gcc-3.2.*)	${ECHO} gcc32;;			\
			egcs*)		${ECHO} egcs;;			\
			*)		${ECHO} gcc;;			\
			esac
PKG_COMPILER=		${PKG_COMPILER_cmd:sh}
.endif

MAKE_ENV+=	PKG_EST_HOME=${SPEECHTOOLS:Q}				\
		EST_HOME=${SPEECHTOOLS:Q}				\
		PKG_FESTIVAL_BUILD_HOME=${FESTIVAL:Q}			\
		PKG_FESTIVAL_HOME=${FHOME:Q}				\
		PKG_COMPILER=${PKG_COMPILER:Q}				\
		PKG_X11BASE=${X11BASE:Q}				\
		PKG_PREFIX=${PREFIX:Q}					\
		EGCS_CC=${CC:Q}						\
		EGCS_CXX=${CXX:Q}					\
		GCC295_CC=${CC:Q}					\
		GCC295_CXX=${CXX:Q}					\
		GCC28_CC=${CC:Q}					\
		GCC28_CXX=${CXX:Q}					\
		GCC27_CC=${CC:Q}					\
		GCC27_CXX=${CXX:Q}					\
		CC=${CC:Q}						\
		CXX=${CXX:Q}

INSTALLATION_DIRS=	bin libexec ${PKGMANDIR}/man1

post-patch:
	${CP} ${FILESDIR}/top-Makefile ${WRKSRC}/Makefile
.if exists(${FILESDIR}/unknown_${OPSYS}.mak)
	${CP} ${FILESDIR}/unknown_${OPSYS}.mak ${SPEECHTOOLS}/config/systems
	${CP} ${FILESDIR}/unknown_${OPSYS}.mak ${FESTIVAL}/config/systems
.endif

# from festival/config/system.sh
.if exists(/etc/redhat-release)
FESTOS=		RedHatLinux
.elif exists(/etc/debian_version)
FESTOS=		DebianGNULinux
.else
FESTOS=		${OPSYS}
.endif

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}
	${CHMOD} -R u+w,a+r,og-w ${FESTIVAL}/lib
	${FIND} ${FESTIVAL}/lib -type d -print | ${XARGS} ${CHMOD} 755
	-@${MV} ${FESTIVAL}/lib/etc/unknown_${FESTOS}			\
		${FESTIVAL}/lib/etc/pkgsrc
	cd ${FESTIVAL} && pax -rw lib examples ${DESTDIR}${FHOME}
	${RM} ${DESTDIR}${FHOME}/examples/Makefile.orig
	${RM} -f ${DESTDIR}${FHOME}/lib/etc/unknown_${FESTOS}/audsp	\
		${DESTDIR}${FHOME}/lib/etc/pkgsrc/audsp
	${INSTALL_PROGRAM} ${FESTIVAL}/lib/etc/pkgsrc/audsp		\
		${DESTDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival		\
		${DESTDIR}${PREFIX}/libexec/festival.naked
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival_client		\
		${DESTDIR}${PREFIX}/libexec/festival_client.naked
	for n in festival.sh festival_client.sh sitevars.scm; do	\
		${SED} "s%@PKG_FESTIVAL_LOCATION@%${FHOME}%;		\
			s%@PKG_PREFIX@%${PREFIX}%" < ${FILESDIR}/$$n	\
			> ${WRKDIR}/$$n ;				\
	done
	${INSTALL_SCRIPT} ${WRKDIR}/festival.sh				\
		${DESTDIR}${PREFIX}/bin/festival
	${INSTALL_SCRIPT} ${WRKDIR}/festival_client.sh			\
		${DESTDIR}${PREFIX}/bin/festival_client
	${INSTALL_DATA} ${WRKDIR}/sitevars.scm				\
		${DESTDIR}${FHOME}/lib/sitevars.scm
	${INSTALL_MAN} ${FESTIVAL}/doc/festival.1			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/festival.1
	${INSTALL_MAN} ${FESTIVAL}/doc/festival_client.1		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/festival_client.1

.include "../../audio/nas/buildlink3.mk"
.if ${OPSYS} == "Linux"
# See DebianGNULinux.mak
.include "../../mk/curses.buildlink3.mk"
.endif
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
