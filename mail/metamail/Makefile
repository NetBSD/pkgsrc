# $NetBSD: Makefile,v 1.22.2.2 2004/03/05 16:25:45 agc Exp $

DISTNAME=	mm2.7
PKGNAME=	metamail-2.7
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	ftp://thumper.bellcore.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Implementation of MIME, the Multipurpose Internet Mail Extensions

CONFLICTS+=	elm>=2.5.5 mm-2.7

USE_BUILDLINK2=		YES
WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_PKGINSTALL=		YES
USE_X11=		YES

CFLAGS+=	-DPKG_SYSCONFDIR='\\\"${PKG_SYSCONFDIR}\\\"'
MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR} CHMOD=${CHMOD} SED=${SED}

EGDIR=		${PREFIX}/share/examples/metamail
CONF_FILES=	${EGDIR}/mailcap ${PKG_SYSCONFDIR}/mailcap

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=		-DSYSV
.endif

post-patch:
	${RM} -f ${WRKDIR}/mm2.7/src/bin/*.orig

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
