# $NetBSD: Makefile,v 1.3 2024/02/28 04:14:16 schmonz Exp $

DISTNAME=		bincimap-2.0.15
CATEGORIES=		mail
MASTER_SITES=		https://www.fehcom.de/binc/
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.fehcom.de/binc/binc.html
COMMENT=		IMAP server for Maildir using checkpassword
LICENSE=		gnu-gpl-v2

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		pkg_alternatives-[0-9]*:../../pkgtools/pkg_alternatives
DEPENDS+=		qmail-acceptutils-[0-9]*:../../mail/qmail-acceptutils
DEPENDS+=		ucspi-ssl-[0-9]*:../../net/ucspi-ssl

WRKSRC=			${WRKDIR}/mail/bincimap/${DISTNAME}

USE_LANGUAGES=		c++
USE_TOOLS+=		mandoc
REPLACE_PERL=		scripts/*.pl
PKG_SYSCONFSUBDIR=	${PKGBASE}

DJB_SLASHPACKAGE=	YES
DJB_CONFIG_DIR=		${WRKSRC}

PKG_USERS_VARS+=	BINCIMAP_USER BINCIMAP_LOG_USER
PKG_GROUPS_VARS+=	BINCIMAP_GROUP
PKG_GROUPS+=		${BINCIMAP_GROUP}
PKG_USERS+=		${BINCIMAP_USER}:${BINCIMAP_GROUP}
PKG_USERS+=		${BINCIMAP_LOG_USER}:${BINCIMAP_GROUP}

EGDIR=			share/examples/${PKGBASE}

FILES_SUBST+=		BINCIMAP_GROUP=${BINCIMAP_GROUP:Q}
FILES_SUBST+=		BINCIMAP_LOG_USER=${BINCIMAP_LOG_USER:Q}
FILES_SUBST+=		BINCIMAP_USER=${BINCIMAP_USER:Q}
USE_TOOLS+=		openssl:run
FILES_SUBST+=		OPENSSL=${OPENSSL}
.include "../../security/openssl/builtin.mk"
FILES_SUBST+=		SSLDIR=${SSLDIR}
FILES_SUBST+=		UCSPI_SSL_USER=${UCSPI_SSL_USER:Q}
FILES_SUBST+=		UCSPI_SSL_GROUP=${UCSPI_SSL_GROUP:Q}
RCD_SCRIPTS=		bincimapd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/man7
INSTALLATION_DIRS+=	${EGDIR}

BUILD_DEFS+=		BINCIMAP_LOG_USER UCSPI_SSL_USER UCSPI_SSL_GROUP
BUILD_DEFS+=		QMAILDIR SSLDIR

post-build:
	cd ${WRKSRC}/man; for f in *.9; do				\
		${MAKE} $$(${BASENAME} $${f} .9).1;			\
	done

do-install:
	for f in ${WRKSRC}/command/*; do				\
		${INSTALL_PROGRAM} $${f} ${DESTDIR}${PREFIX}/bin;	\
	done
	for f in ${WRKSRC}/scripts/*.pl; do				\
		${INSTALL_SCRIPT} $${f}					\
		${DESTDIR}${PREFIX}/${EGDIR}/$$(${BASENAME} $${f} .pl);	\
	done
	for f in ${WRKSRC}/man/*.[1-8]; do				\
		${INSTALL_MAN} $${f}					\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$(${ECHO} $${f} | ${AWK} -F. '{print $$NF}'); \
	done

.include "options.mk"

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
