# $NetBSD: Makefile,v 1.24 2004/01/20 12:19:43 agc Exp $

DISTNAME=	mm2.7
PKGNAME=	metamail-2.7
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://thumper.bellcore.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Implementation of MIME, the Multipurpose Internet Mail Extensions

CONFLICTS+=	elm>=2.5.5 mm-2.7

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_X11=		YES

CFLAGS+=	-DPKG_SYSCONFDIR='\\\"${PKG_SYSCONFDIR}\\\"'
MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/metamail
CONF_FILES=	${EGDIR}/mailcap ${PKG_SYSCONFDIR}/mailcap

INSTALLATION_DIRS=	bin man/man1 man/man4

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DSYSV
.endif

post-patch:
	${RM} -f ${WRKDIR}/mm2.7/src/bin/*.orig

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
