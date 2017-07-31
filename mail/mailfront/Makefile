# $NetBSD: Makefile,v 1.16 2017/07/31 20:38:51 schmonz Exp $
#

DISTNAME=		mailfront-2.12
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}archive/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/mailfront/
COMMENT=		Mail server network protocol front-ends
LICENSE=		gnu-gpl-v2

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS_QMAIL=		qmail>=1.03nb8:../../mail/qmail
DEPENDS+=		${DEPENDS_QMAIL}

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO
BUILD_TARGET=		all
DJB_CONFIG_CMDS+=	${ECHO} ${PREFIX}/include > conf-include;	\
			${ECHO} ${PREFIX}/lib/${PKGBASE} > conf-modules;

FILES_SUBST+=		QMAIL_DAEMON_USER=${QMAIL_DAEMON_USER:Q}
FILES_SUBST+=		QMAIL_LOG_USER=${QMAIL_LOG_USER:Q}
RCD_SCRIPTS=		smtpfront
INSTALLATION_DIRS=	share/doc/mailfront
INSTALL_ENV+=		install_prefix=${DESTDIR:Q}

BUILD_DEFS+=		QMAIL_DAEMON_USER QMAIL_LOG_USER

USE_LIBTOOL=		yes

MAKE_JOBS_SAFE=		no # due to hacky libtoolization

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

post-install:
	cd ${WRKSRC};							\
	for f in ANNOUNCEMENT NEWS README *.html; do			\
		${INSTALL_DATA} $${f} 					\
			${DESTDIR}${PREFIX}/share/doc/mailfront;	\
	done

# Detect the PKG_SYSCONFDIR of the installed qmail, so we can create
# config files there and refer to them from rc.d scripts.
#
.if !defined(PKG_SYSCONFDIR.mailfront)
PKG_SYSCONFDIR.mailfront!=						\
	${PKG_INFO} -Q PKG_SYSCONFDIR					\
		${DEPENDS_QMAIL:C/:.*$//:Q} 2>/dev/null ||		\
	${ECHO} "PKG_SYSCONFDIR.mailfront_not_set"
.  if empty(PKG_SYSCONFDIR.mailfront:M*not_set)
MAKEVARS+=	PKG_SYSCONFDIR.mailfront
.  endif
.endif

BUILDLINK_API_DEPENDS.bglibs+=	bglibs>=2.01
.include "../../devel/bglibs/buildlink3.mk"
BUILDLINK_API_DEPENDS.cvm+=	cvm>=0.97
.include "../../security/cvm/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
