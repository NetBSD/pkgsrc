# $NetBSD: Makefile,v 1.4 2001/02/25 04:17:36 hubertf Exp $
#

DISTNAME=	dgguspat
PKGNAME=	guspatches-1.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.zip

MAINTAINER=     packages@netbsd.org
COMMENT=	GUS (Gravis Ultrasound) patches (audio samples) for TiMidity

CONFLICTS=	eawpatches-*

RESTRICTED=		"Uses copyrighted patches"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes

do-build:
	${SED} "s|@PREFIX@|${PREFIX}|" < ${FILESDIR}/gravis.cfg > \
		${WRKDIR}/gravis.cfg
	${SED} "s|@PREFIX@|${PREFIX}|" < ${FILESDIR}/timidity.cfg > \
		${WRKDIR}/timidity.cfg

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/timidity
	cd ${PREFIX}/share/timidity && unzip -oqL ${DISTDIR}/${DISTFILES}
	${INSTALL_DATA} ${FILESDIR}/midia.cfg ${PREFIX}/share/timidity
	${INSTALL_DATA} ${WRKDIR}/gravis.cfg ${PREFIX}/share/timidity
	${INSTALL_DATA} ${WRKDIR}/timidity.cfg ${PREFIX}/share/timidity

.include "../../mk/bsd.pkg.mk"
