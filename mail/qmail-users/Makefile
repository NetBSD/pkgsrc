# $NetBSD: Makefile,v 1.1.1.1 2001/11/26 22:20:32 zuntum Exp $
#

DISTNAME=	qmail-users-1.0
CATEGORIES=	mail
MASTER_SITES=   #
DISTFILES=	#

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.qmail.org/
COMMENT=	Users required to build & run qmail package

QMAILDIR?=	/var/qmail

PKG_GROUPS=	qmail nofiles

PKG_USERS+=	alias:nofiles::alias:${QMAILDIR}/alias
PKG_USERS+=	qmaill:nofiles::qmaill:${QMAILDIR}
PKG_USERS+=	qmaild:nofiles::qmaild:${QMAILDIR}
PKG_USERS+=	qmailp:nofiles::qmailp:${QMAILDIR}
PKG_USERS+=	qmailq:qmail::qmailq:${QMAILDIR}
PKG_USERS+=	qmailr:qmail::qmailr:${QMAILDIR}
PKG_USERS+=	qmails:qmail::qmails:${QMAILDIR}

NO_BUILD=	YES

WRKSRC=		${WRKDIR}

do-install:

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
