# $NetBSD: Makefile,v 1.1.1.1 2000/06/05 14:37:58 rh Exp $
#

DISTNAME=	amavis-0.2.0-pre6
PKGNAME=	amavis-0.2.0p6
CATEGORIES=	security mail
MASTER_SITES=	http://aachalon.de/AMaViS/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://satan.oih.rwth-aachen.de/AMaViS/amavis.html

DEPENDS+=	uvscan-[0-9]*:../../security/uvscan
DEPENDS+=	mm-*:../../mail/metamail
DEPENDS+=	unzip-*:../../archivers/unzip
DEPENDS+=	unarj-*:../../archivers/unarj
DEPENDS+=	unrar-*:../../archivers/unrar
DEPENDS+=	xbin-*:../../archivers/xbin
DEPENDS+=	lha-*:../../archivers/lha
DEPENDS+=	zoo-*:../../archivers/zoo
DEPENDS+=	freeze-*:../../archivers/freeze
DEPENDS+=	arc-*:../../archivers/arc

VIRUSDIR?=	/var/log/virusmails	# where to put contaminated mails
VIRUSMAILTO?=	security		# whom to notify about viruses

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-virusdir=${VIRUSDIR}
CONFIGURE_ARGS+=--with-mailto=${VIRUSMAILTO}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/zipsecure/zipsecure ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/securetar/securetar ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/scanmails/scanmails ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
