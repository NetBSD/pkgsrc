# $NetBSD: Makefile,v 1.1 2022/02/05 13:50:22 schmonz Exp $

DISTNAME=		qtraceaddr
PKGNAME=		${DISTNAME}-20061202
CATEGORIES=		mail
MASTER_SITES=		https://code.dogmap.org./qmail/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		# none

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://code.dogmap.org./qmail/\#qtraceaddr
COMMENT=		Illustrates how qmail would deliver to an address
LICENSE=		public-domain

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		# none
USE_TOOLS+=		perl:run
NO_BUILD=		yes

REPLACE_PERL=		${PKGBASE}

SUBST_CLASSES+=		defs
SUBST_STAGE.defs=	do-configure
SUBST_FILES.defs=	${PKGBASE}
SUBST_VARS.defs=	QMAILDIR QMAIL_ALIAS_USER

BUILD_DEFS+=		QMAILDIR QMAIL_ALIAS_USER

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
