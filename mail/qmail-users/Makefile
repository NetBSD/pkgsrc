# $NetBSD: Makefile,v 1.6 2003/07/17 21:46:56 grant Exp $
#

DISTNAME=	qmail-users-1.0
WRKSRC=		${WRKDIR}
CATEGORIES=	mail
MASTER_SITES=   #
DISTFILES=	#

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.qmail.org/
COMMENT=	Users required to build & run qmail package

PKG_GROUPS=	qmail nofiles

PKG_USERS+=	alias:nofiles::alias:${QMAILDIR}/alias
PKG_USERS+=	qmaill:nofiles::qmaill:${QMAILDIR}
PKG_USERS+=	qmaild:nofiles::qmaild:${QMAILDIR}
PKG_USERS+=	qmailp:nofiles::qmailp:${QMAILDIR}
PKG_USERS+=	qmailq:qmail::qmailq:${QMAILDIR}
PKG_USERS+=	qmailr:qmail::qmailr:${QMAILDIR}
PKG_USERS+=	qmails:qmail::qmails:${QMAILDIR}

NO_BUILD=	YES
NO_CHECKSUM=	YES
USE_PKGINSTALL=	YES

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
