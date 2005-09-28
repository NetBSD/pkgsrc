# $NetBSD: Makefile,v 1.4 2005/09/28 20:52:24 rillig Exp $
#

DISTNAME=		qgreylist-0.2
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
NO_BUILD=		yes

QGREYLIST_SCRIPTS=	greylist greylist-info
REPLACE_PERL=		${QGREYLIST_SCRIPTS}

.include "../../mk/bsd.prefs.mk"

# Detect the PKG_SYSCONFDIR of the installed qmail, so we can create
# config files there.
.if !empty(PHASES_AFTER_EXTRACT:M${PKG_PHASE})
INSTALLED_QMAIL!= ${PKG_BEST_EXISTS} ${DEPENDS_QMAIL:C/:.*$//:Q:S/\ / /g}
.  if empty(INSTALLED_QMAIL:M*_not_found_)
.    if !defined(PKG_SYSCONFDIR.qgreylist)
PKG_SYSCONFDIR.qgreylist!= \
	${PKG_INFO} -qB ${INSTALLED_QMAIL} |				\
		${SED} -n '/^PKG_SYSCONFDIR=/s|^PKG_SYSCONFDIR=[ 	]*||p'
.    endif
.  endif
.endif

SUBST_CLASSES+=		qmaildirs
SUBST_STAGE.qmaildirs=	do-configure
SUBST_FILES.qmaildirs=	${QGREYLIST_SCRIPTS}
SUBST_SED.qmaildirs=	-e 's|/var/qmail/greylist|${PKG_SYSCONFDIR}/greylist|g'
SUBST_SED.qmaildirs+=	-e 's|/var/qmail|${QMAILDIR}|g'

INSTALLATION_DIRS=	bin share/doc/qgreylist

do-install:
	for i in ${QGREYLIST_SCRIPTS}; do				\
		${INSTALL_SCRIPT} ${WRKSRC}/$${i} ${PREFIX}/bin/q$${i};	\
	done
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/qgreylist

.include "../../mk/bsd.pkg.mk"
