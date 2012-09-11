# $NetBSD: Makefile,v 1.27 2012/09/11 23:59:30 asau Exp $

DISTNAME=		daapd-0.2.4b
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tgz

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.deleet.de/projekte/daap/daapd/
COMMENT=		Server for DAA protocol (iTunes)

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKE_FILE=		makefile

RCD_SCRIPTS=		daapd
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=		${EGDIR}/daapd.conf ${PKG_SYSCONFDIR}/daapd.conf

.include "options.mk"

MAKE_ENV+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	daapd.8 daapd.cc
SUBST_SED.paths=	-e 's,/etc/,${PKG_SYSCONFDIR}/,g'

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man8 ${EGDIR}

post-extract:
	for FILE in `${FIND} ${WRKSRC}/daaplib -type f -print`; do	\
	  ${TR} -d \\r <$${FILE} >$${FILE}.new;				\
	  ${MV} $${FILE}.new $${FILE};					\
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/daapd ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/daapd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/daapd-example.conf ${DESTDIR}${EGDIR}/daapd.conf

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
