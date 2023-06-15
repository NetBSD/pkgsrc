# $NetBSD: Makefile,v 1.1 2023/06/15 09:55:25 hauke Exp $

DISTNAME=	and-1.2.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=and/}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://and.sourceforge.net/
COMMENT=	Renice or kill jobs based on priority database
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

USE_LANGUAGES=	c

BUILD_TARGET=	and doc

RCD_SCRIPTS=	and

EGDIR=		share/examples/and
CONFIG_FILES=	and.conf and.priorities

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile
SUBST_FILES.paths+=	and.service
SUBST_VARS.paths=	PREFIX PKG_SYSCONFDIR VARBASE

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Fixing hardcoded paths in man pages.
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	*.man
SUBST_SED.man=		-e 's,/etc/,${PKG_SYSCONFDIR}/,g'

LIBS.NetBSD+=		-lkvm
LIBS.FreeBSD+=		-lkvm

MAKE_FLAGS+=		LD=${CC:Q} LIBS=${LIBS:Q}

.for f in ${CONFIG_FILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 ${EGDIR}

post-extract:
	cp ${FILESDIR}/and.service ${WRKSRC}/
	cp ${WRKSRC}/and-OpenBSD.c ${WRKSRC}/and-NetBSD.c


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/and ${DESTDIR}${PREFIX}/sbin/and
.for mp in and.conf and.priorities
	${INSTALL_MAN} ${WRKSRC}/${mp}.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/
.endfor
	${INSTALL_MAN} ${WRKSRC}/and.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
.for cf in ${CONFIG_FILES} and.init.debian and.service and.startup
	${INSTALL_DATA} ${WRKSRC}/${cf} ${DESTDIR}${PREFIX}/${EGDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
