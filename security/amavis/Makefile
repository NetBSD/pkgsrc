# $NetBSD: Makefile,v 1.9 2001/10/22 06:41:29 martti Exp $
#

DISTNAME=	amavis-0.2.1
PKGNAME=	amavis-0.2.1nb4
CATEGORIES=	security mail
MASTER_SITES=	http://www.amavis.org/dist/ \
		http://aachalon.de/AMaViS/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.amavis.org/
COMMENT=	mail virus scanner

DEPENDS+=	uvscan-[0-9]*:../../security/uvscan
DEPENDS+=	maildrop-[0-9]*:../../mail/maildrop
DEPENDS+=	tnef-[0-9]*:../../mail/tnef
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	unarj-[0-9]*:../../archivers/unarj
DEPENDS+=	unrar-[0-9]*:../../archivers/unrar
DEPENDS+=	xbin-[0-9]*:../../archivers/xbin
DEPENDS+=	lha-[0-9]*:../../archivers/lha
DEPENDS+=	zoo-[0-9]*:../../archivers/zoo
DEPENDS+=	freeze-[0-9]*:../../archivers/freeze
DEPENDS+=	arc-[0-9]*:../../archivers/arc

VIRUSDIR?=	/var/log/virusmails	# where to put contaminated mails
VIRUSMAILTO?=	security		# whom to notify about viruses

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	procmail="/usr/libexec/mail.local"
CONFIGURE_ARGS+=--with-virusdir=${VIRUSDIR}
CONFIGURE_ARGS+=--with-mailto=${VIRUSMAILTO}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/zipsecure/zipsecure ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/securetar/securetar ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/scanmails/scanmails ${PREFIX}/sbin
	${SED} -e 's#@PREFIX@#${PREFIX}#g' < ${FILESDIR}/amavis.m4 \
		>${WRKDIR}/amavis.m4
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/amavis
	${INSTALL_DATA} ${FILESDIR}/LICENSE.sendmail ${PREFIX}/share/examples/amavis
	${INSTALL_DATA} ${WRKDIR}/amavis.m4 ${PREFIX}/share/examples/amavis

.include "../../mk/bsd.pkg.mk"
