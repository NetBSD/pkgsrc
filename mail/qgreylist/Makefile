# $NetBSD: Makefile,v 1.17 2016/07/09 06:38:31 wiz Exp $
#

DISTNAME=		qgreylist-0.3
PKGREVISION=		5
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.jonatkins.com/page/software/qgreylist
COMMENT=		Simple greylisting for qmail

DEPENDS_QMAIL=		qmail>=1.03nb8:../../mail/qmail
DEPENDS+=		${DEPENDS_QMAIL}

WRKSRC=			${WRKDIR}/qgreylist

USE_TOOLS+=		perl:run
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/greylist qmaild wheel 0755
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/whitelist qmaild wheel 0755
NO_BUILD=		yes

REPLACE_PERL=		greylist

.include "../../mk/bsd.prefs.mk"

# Detect the PKG_SYSCONFDIR of the installed qmail, so we can create
# config files there and refer to them from rc.d scripts.
#
.if !defined(PKG_SYSCONFDIR.qgreylist)
PKG_SYSCONFDIR.qgreylist!=						\
	${PKG_INFO} -Q PKG_SYSCONFDIR					\
		${DEPENDS_QMAIL:C/:.*$//:Q} 2>/dev/null ||		\
	${ECHO} "PKG_SYSCONFDIR.qgreylist_not_set"
.  if empty(PKG_SYSCONFDIR.qgreylist:M*not_set)
MAKEVARS+=	PKG_SYSCONFDIR.qgreylist
.  endif
.endif

SUBST_CLASSES+=		qmaildirs
SUBST_STAGE.qmaildirs=	do-configure
SUBST_FILES.qmaildirs=	greylist
SUBST_SED.qmaildirs=	-e 's|/var/qmail/greylist|${PKG_SYSCONFDIR}/greylist|g'
SUBST_SED.qmaildirs+=	-e 's|/var/qmail/whitelist|${PKG_SYSCONFDIR}/whitelist|g'
SUBST_SED.qmaildirs+=	-e 's|/var/qmail|${QMAILDIR}|g'

INSTALLATION_DIRS=	bin share/doc/qgreylist
BUILD_DEFS+=		QMAILDIR

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/greylist ${DESTDIR}${PREFIX}/bin/qgreylist
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/qgreylist

.include "../../mk/bsd.pkg.mk"
