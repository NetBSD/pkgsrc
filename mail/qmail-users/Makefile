# $NetBSD: Makefile,v 1.3 2002/01/28 17:51:11 zuntum Exp $
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

WRKSRC=		${WRKDIR}

do-install:	# empty

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
