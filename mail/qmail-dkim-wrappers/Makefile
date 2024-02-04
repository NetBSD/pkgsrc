# $NetBSD: Makefile,v 1.1 2024/02/04 07:12:13 schmonz Exp $

PKGNAME=		qmail-dkim-wrappers-0.0.20211012
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
DIST_SUBDIR=		${PKGNAME_NOREV}
DISTFILES=		qmail-remote.sh.txt dkverifier.sh.txt

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.memoryhole.net/qmail/\#dkim
COMMENT=		Sign and verify DKIM without patching qmail

DEPENDS+=		p5-Mail-DKIM>=1.20240124nb1:../../mail/p5-Mail-DKIM

WRKSRC=			${WRKDIR}

USE_TOOLS+=		bash:run
NO_BUILD=		yes

REPLACE_BASH=		qmail-dkim*

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	qmail-dkim*
SUBST_SED.paths=	-e 's|^PATH=|PATH=${PREFIX}/bin:|g'
SUBST_SED.paths+=	-e 's|/var/qmail|${QMAILDIR}|g'
SUBST_SED.paths+=	-e 's|qmail-remote\.orig|qmail-remote|g'
SUBST_SED.paths+=	-e 's|/etc|${PKG_SYSCONFDIR}|g'

INSTALLATION_DIRS=	bin

BUILD_DEFS+=		QMAILDIR

post-extract:
	cd ${WRKSRC};						\
	${MV} -f qmail-remote.sh.txt qmail-dkimsign-remote;	\
	${MV} -f dkverifier.sh.txt qmail-dkimverify-queue

do-install:
	cd ${WRKSRC};						\
	for f in qmail-dkim*; do				\
		${INSTALL_SCRIPT} $$f ${DESTDIR}${PREFIX}/bin/;	\
	done

.include "../../mk/bsd.pkg.mk"
