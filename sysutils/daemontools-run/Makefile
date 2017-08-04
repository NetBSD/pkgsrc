# $NetBSD: Makefile,v 1.4 2017/08/04 18:44:15 schmonz Exp $
#

DISTNAME=		daemontools-run-20170804
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Configures daemontools to run supervised services
LICENSE=		2-clause-bsd

DEPENDS_DAEMONTOOLS=	daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		${DEPENDS_DAEMONTOOLS}

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

.include "../../mk/bsd.prefs.mk"

# Detect the PKG_SYSCONFDIR of the installed daemontools, so we can create
# config files there and refer to them from rc.d scripts.
#
.if !defined(PKG_SYSCONFDIR.daemontools-run)
PKG_SYSCONFDIR.daemontools-run!=					\
	${PKG_INFO} -Q PKG_SYSCONFDIR					\
		${DEPENDS_DAEMONTOOLS:C/:.*$//:Q} 2>/dev/null ||	\
	${ECHO} "PKG_SYSCONFDIR.daemontools-run_not_set"
.  if empty(PKG_SYSCONFDIR.daemontools-run:M*not_set)
MAKEVARS+=	PKG_SYSCONFDIR.daemontools-run
.  endif
.endif

do-install:
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc ${DESTDIR}${PREFIX}/share/doc/daemontools-run

.include "../../mk/bsd.pkg.mk"
