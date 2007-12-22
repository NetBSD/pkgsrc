# $NetBSD: Makefile,v 1.44 2007/12/22 19:12:27 minskim Exp $

DISTNAME=	mm2.7
PKGNAME=	metamail-2.7
PKGREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	http://ftp.funet.fi/pub/unix/mail/metamail/	\
		ftp://ftp.research.telcordia.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Implementation of MIME, the Multipurpose Internet Mail Extensions

CONFLICTS+=	elm>=2.5.5 mm-2.7

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/src

CFLAGS.Linux+=	-DLINUX
CFLAGS.SunOS+=	-DSYSV
MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q} CHMOD=${CHMOD:Q} SED=${SED:Q}

EGDIR=		${PREFIX}/share/examples/metamail
CONF_FILES=	${EGDIR}/mailcap ${PKG_SYSCONFDIR}/mailcap
USE_TOOLS+=	bdftopcf csh:run

REPLACE_INTERPRETER+=	csh
REPLACE.csh.old=	/bin/csh
REPLACE.csh.new=	${CSH}
REPLACE_FILES.csh=	bin/audiocompose bin/audiosend bin/extcompose
REPLACE_FILES.csh+=	bin/getfilename bin/mailserver bin/mailto-hebrew
REPLACE_FILES.csh+=	bin/metasend bin/patch-metamail bin/showaudio
REPLACE_FILES.csh+=	bin/showexternal bin/shownonascii bin/showpartial
REPLACE_FILES.csh+=	bin/showpicture bin/sun-audio-file bin/sun-message.csh
REPLACE_FILES.csh+=	bin/sun-to-mime
REPLACE_FILES.csh+=	fonts/Xmailto-hebrew fonts/Xshownonascii

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man4

SUBST_CLASSES+=		awk sys
SUBST_STAGE.awk=	post-patch
SUBST_MESSAGE.awk=	Adjusting the path to awk
SUBST_FILES.awk=	bin/sun2mime
SUBST_SED.awk=		-e "s|/bin/nawk|${AWK}|"
SUBST_STAGE.sys=	post-patch
SUBST_MESSAGE.sys=	Adjusting the path for PKG_SYSCONFDIR.
SUBST_FILES.sys=	config.h
SUBST_SED.sys=		-e "s|PKG_SYSCONFDIR|\"${PKG_SYSCONFDIR}\"|g"

post-patch:
	${RM} -f ${WRKDIR}/mm2.7/src/bin/*.orig

pre-configure:
	if ${GREP} putenv /usr/include/stdlib.h >/dev/null;		\
	then								\
		cd ${WRKSRC}/metamail;					\
		${MV} Makefile Makefile.pre-sed;			\
		${SED} -e s/putenv.o//g Makefile.pre-sed >Makefile;	\
	fi

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
