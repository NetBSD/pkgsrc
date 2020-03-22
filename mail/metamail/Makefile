# $NetBSD: Makefile,v 1.54 2020/03/22 18:28:15 rillig Exp $

DISTNAME=	mm2.7
PKGNAME=	metamail-2.7
PKGREVISION=	12
CATEGORIES=	mail
MASTER_SITES=	http://ftp.funet.fi/pub/unix/mail/metamail/
MASTER_SITES+=	ftp://ftp.research.telcordia.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Implementation of MIME, the Multipurpose Internet Mail Extensions

CONFLICTS+=	mm-2.7{,nb*}

WRKSRC=		${WRKDIR}/${DISTNAME}/src

CFLAGS.Linux+=	-DLINUX
CFLAGS.SunOS+=	-DSYSV
MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR} CHMOD=${CHMOD:Q} SED=${SED:Q}

EGDIR=		${PREFIX}/share/examples/metamail
CONF_FILES=	${EGDIR}/mailcap ${PKG_SYSCONFDIR}/mailcap
USE_TOOLS+=	bdftopcf csh:run

REPLACE_CSH=	bin/* fonts/*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man4 ${EGDIR}

SUBST_CLASSES+=		awk
SUBST_STAGE.awk=	pre-configure
SUBST_MESSAGE.awk=	Adjusting the path to awk
SUBST_FILES.awk=	bin/sun2mime
SUBST_SED.awk=		-e "s|/bin/nawk|${AWK}|"

SUBST_CLASSES+=		sys
SUBST_STAGE.sys=	pre-configure
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
