# $NetBSD: Makefile,v 1.35 2005/05/09 13:02:14 xtraeme Exp $

DISTNAME=	mm2.7
PKGNAME=	metamail-2.7
PKGREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	http://ftp.funet.fi/pub/unix/mail/metamail/	\
		ftp://ftp.research.telcordia.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Implementation of MIME, the Multipurpose Internet Mail Extensions

CONFLICTS+=	elm>=2.5.5 mm-2.7

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_PKGINSTALL=		YES

CFLAGS.Linux+=	-DLINUX
CFLAGS.SunOS+=	-DSYSV
MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR} CHMOD=${CHMOD} SED=${SED}

EGDIR=		${PREFIX}/share/examples/metamail
CONF_FILES=	${EGDIR}/mailcap ${PKG_SYSCONFDIR}/mailcap

INSTALLATION_DIRS=	bin man/man1 man/man4

SUBST_CLASSES+=		awk sys
SUBST_STAGE.awk=	post-patch
SUBST_MESSAGE.awk=	Adjusting the path to awk
SUBST_FILES.awk=	bin/sun2mime
SUBST_SED.awk=		-e "s|/bin/nawk|${AWK}|"
SUBST_STAGE.sys=	post-patch
SUBST_MESSAGE.sys=	"Adjusting the path for PKG_SYSCONFDIR"
SUBST_FILES.sys=	config.h
SUBST_SED.sys=		-e "s|PKG_SYSCONFDIR|\"${PKG_SYSCONFDIR}\"|g"

post-patch:
	${RM} -f ${WRKDIR}/mm2.7/src/bin/*.orig

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../mk/x11-clients.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
