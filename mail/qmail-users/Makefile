# $NetBSD: Makefile,v 1.4 2003/01/28 22:03:37 jlam Exp $
#

DISTNAME=	qmail-users-1.0
CATEGORIES=	mail
MASTER_SITES=   #
DISTFILES=	#

MAINTAINER=	zuntum@netbsd.org
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

WRKSRC=		${WRKDIR}

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
