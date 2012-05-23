# $NetBSD: Makefile,v 1.48 2012/05/23 03:59:33 dholland Exp $

DISTNAME=	mm2.7
PKGNAME=	metamail-2.7
PKGREVISION=	10
CATEGORIES=	mail
MASTER_SITES=	http://ftp.funet.fi/pub/unix/mail/metamail/	\
		ftp://ftp.research.telcordia.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Implementation of MIME, the Multipurpose Internet Mail Extensions

CONFLICTS+=	mm-2.7

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/src

CFLAGS.Linux+=	-DLINUX
CFLAGS.SunOS+=	-DSYSV
MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR} CHMOD=${CHMOD:Q} SED=${SED:Q}

EGDIR=		${PREFIX}/share/examples/metamail
CONF_FILES=	${EGDIR}/mailcap ${PKG_SYSCONFDIR}/mailcap
USE_TOOLS+=	bdftopcf csh:run

REPLACE_CSH=	bin/audiocompose bin/audiosend bin/extcompose
REPLACE_CSH+=	bin/getfilename bin/mailserver bin/mailto-hebrew
REPLACE_CSH+=	bin/metasend bin/patch-metamail bin/showaudio
REPLACE_CSH+=	bin/showexternal bin/shownonascii bin/showpartial
REPLACE_CSH+=	bin/showpicture bin/sun-audio-file bin/sun-message.csh
REPLACE_CSH+=	bin/sun-to-mime
REPLACE_CSH+=	fonts/Xmailto-hebrew fonts/Xshownonascii

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man4 ${EGDIR}

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
	set -e;								\
	if ${GREP} putenv /usr/include/stdlib.h >/dev/null;		\
	then								\
		cd ${WRKSRC}/metamail;					\
		${MV} Makefile Makefile.pre-sed;			\
		${SED} -e s/putenv.o//g Makefile.pre-sed >Makefile;	\
	fi

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
