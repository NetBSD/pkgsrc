# $NetBSD: Makefile,v 1.16 2005/12/05 20:50:54 rillig Exp $
#

DISTNAME=	amavis-0.2.1
PKGREVISION=	5
CATEGORIES=	security mail
MASTER_SITES=	http://www.amavis.org/dist/ \
		http://aachalon.de/AMaViS/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.amavis.org/
COMMENT=	Mail virus scanner

CONFLICTS+=	amavis-perl-[0-9]*

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
CONFIGURE_ENV+=	BASH=${TOOLS_SH:Q}
CONFIGURE_ARGS+=--with-virusdir=${VIRUSDIR}
CONFIGURE_ARGS+=--with-mailto=${VIRUSMAILTO}

INSTALLATION_DIRS=	bin sbin

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
