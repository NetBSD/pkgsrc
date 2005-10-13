# $NetBSD: Makefile,v 1.5 2005/10/13 17:01:46 schmonz Exp $
#

DISTNAME=		qgreylist-0.3
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.jonatkins.com/qgreylist/
COMMENT=		Simple greylisting for qmail

DEPENDS_QMAIL=		qmail>=1.03nb8:../../mail/qmail
DEPENDS+=		${DEPENDS_QMAIL}

WRKSRC=			${WRKDIR}/qgreylist

USE_TOOLS+=		perl:run
USE_PKGINSTALL=		yes
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/greylist qmaild wheel 0755
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/whitelist qmaild wheel 0755
NO_BUILD=		yes

REPLACE_PERL=		greylist

.include "../../mk/bsd.prefs.mk"

# Detect the PKG_SYSCONFDIR of the installed qmail, so we can create
# config files there.
.if !empty(PHASES_AFTER_EXTRACT:M${PKG_PHASE})
INSTALLED_QMAIL!= ${PKG_BEST_EXISTS} ${DEPENDS_QMAIL:C/:.*$//:Q:S/\ / /g}
.  if empty(INSTALLED_QMAIL:M*_not_found_)
.    if !defined(PKG_SYSCONFDIR.qgreylist)
PKG_SYSCONFDIR.qgreylist!=	${PKG_INFO} -Q PKG_SYSCONFDIR ${INSTALLED_QMAIL}
.    endif
.  endif
.endif

SUBST_CLASSES+=		qmaildirs
SUBST_STAGE.qmaildirs=	do-configure
SUBST_FILES.qmaildirs=	greylist
SUBST_SED.qmaildirs=	-e 's|/var/qmail/greylist|${PKG_SYSCONFDIR}/greylist|g'
SUBST_SED.qmaildirs+=	-e 's|/var/qmail/whitelist|${PKG_SYSCONFDIR}/whitelist|g'
SUBST_SED.qmaildirs+=	-e 's|/var/qmail|${QMAILDIR}|g'

INSTALLATION_DIRS=	bin share/doc/qgreylist

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/greylist ${PREFIX}/bin/qgreylist
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/qgreylist

.include "../../mk/bsd.pkg.mk"
