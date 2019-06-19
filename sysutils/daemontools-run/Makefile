# $NetBSD: Makefile,v 1.9 2019/06/19 17:52:03 schmonz Exp $
#

DISTNAME=		daemontools-run-20190619
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Configures daemontools to run supervised services
LICENSE=		2-clause-bsd

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
NO_CHECKSUM=		yes

MAKE_DIRS+=		${VARBASE}/service
PKG_GROUPS_VARS+=	DAEMONTOOLS_GROUP
PKG_USERS_VARS+=	DAEMONTOOLS_LOG_USER
PKG_GROUPS+=		${DAEMONTOOLS_GROUP}
PKG_USERS+=		${DAEMONTOOLS_LOG_USER}:${DAEMONTOOLS_GROUP}
RCD_SCRIPTS=		svscan
FILES_SUBST+=		VARBASE=${VARBASE:Q}
FILES_SUBST+=		DAEMONTOOLS_LOG_USER=${DAEMONTOOLS_LOG_USER:Q}
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}

INSTALLATION_DIRS=	share/doc/${PKGBASE}
BUILD_DEFS+=		VARBASE DAEMONTOOLS_LOG_USER

.include "options.mk"

do-install:
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc ${DESTDIR}${PREFIX}/share/doc/daemontools-run

.include "../../mk/bsd.pkg.mk"
