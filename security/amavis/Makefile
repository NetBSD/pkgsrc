# $NetBSD: Makefile,v 1.3 2000/10/23 14:52:53 rh Exp $
#

DISTNAME=	amavis-0.2.1-pre3
PKGNAME=	amavis-0.2.1p3
CATEGORIES=	security mail
MASTER_SITES=	http://www.amavis.org/dist/ \
		http://aachalon.de/AMaViS/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.amavis.org/

DEPENDS+=	uvscan-[0-9]*:../../security/uvscan
DEPENDS+=	maildrop-*:../../mail/maildrop
DEPENDS+=	tnef-*:../../mail/tnef
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
CONFIGURE_ENV+=	procmail="/usr/libexec/mail.local"
CONFIGURE_ARGS+=--with-virusdir=${VIRUSDIR}
CONFIGURE_ARGS+=--with-mailto=${VIRUSMAILTO}

MESSAGE_FILE=	${WRKDIR}/MESSAGE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/zipsecure/zipsecure ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/securetar/securetar ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/scanmails/scanmails ${PREFIX}/sbin
	${SED} -e 's#@PREFIX@#${PREFIX}#g' < ${PKGDIR}/MESSAGE \
		>${WRKDIR}/MESSAGE
	${SED} -e 's#@PREFIX@#${PREFIX}#g' < ${FILESDIR}/amavis.m4 \
		>${WRKDIR}/amavis.m4
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/amavis
	${INSTALL_DATA} ${FILESDIR}/LICENSE.sendmail ${PREFIX}/share/examples/amavis
	${INSTALL_DATA} ${WRKDIR}/amavis.m4 ${PREFIX}/share/examples/amavis

.include "../../mk/bsd.pkg.mk"
