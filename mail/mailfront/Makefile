# $NetBSD: Makefile,v 1.3 2005/10/08 21:00:58 schmonz Exp $
#

DISTNAME=		mailfront-0.97
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/mailfront/
COMMENT=		Mail server network protocol front-ends

DEPENDS+=		cvm-[0-9]*:../../security/cvm
DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS_QMAIL=		qmail>=1.03nb8:../../mail/qmail
DEPENDS+=		${DEPENDS_QMAIL}

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

USE_PKGINSTALL=		YES
RCD_SCRIPTS=		smtpfront

.include "../../mk/bsd.prefs.mk"

# Detect the PKG_SYSCONFDIR of the installed qmail, so we can create
# config files there and refer to them from rc.d scripts.
.if !empty(PHASES_AFTER_EXTRACT:M${PKG_PHASE})
INSTALLED_QMAIL!= ${PKG_BEST_EXISTS} ${DEPENDS_QMAIL:C/:.*$//:Q:S/\ / /g}
.  if empty(INSTALLED_QMAIL:M*_not_found_)
.    if !defined(PKG_SYSCONFDIR.mailfront)
PKG_SYSCONFDIR.mailfront!= ${PKG_INFO} -Q PKG_SYSCONFDIR ${INSTALLED_QMAIL}
.    endif
.  endif
.endif

.include "../../devel/bglibs/buildlink3.mk"
.include "../../security/cvm/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
