# $NetBSD: Makefile,v 1.19 2012/09/12 00:24:39 asau Exp $
#

DISTNAME=	dgguspat
PKGNAME=	guspatches-1.0
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GUS (Gravis Ultrasound) patches (audio samples) for TiMidity

RESTRICTED=		Uses copyrighted patches
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
USE_LANGUAGES=		# empty
USE_TOOLS+=		unzip
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

do-configure:
	${SED} "s|@PREFIX@|${PREFIX}|" < ${FILESDIR}/gravis.cfg > \
		${WRKDIR}/gravis.cfg
	${SED} "s|@PREFIX@|${PREFIX}|" < ${FILESDIR}/timidity.cfg > \
		${WRKDIR}/timidity.cfg

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/guspatches
	cd ${DESTDIR}${PREFIX}/share/guspatches && \
		unzip -oqL ${DISTDIR}/${DISTFILES}
	${INSTALL_DATA} ${FILESDIR}/midia.cfg \
		${DESTDIR}${PREFIX}/share/guspatches
	${INSTALL_DATA} ${WRKDIR}/gravis.cfg \
		${DESTDIR}${PREFIX}/share/guspatches
	${INSTALL_DATA} ${WRKDIR}/timidity.cfg \
		${DESTDIR}${PREFIX}/share/guspatches

.include "../../mk/bsd.pkg.mk"
