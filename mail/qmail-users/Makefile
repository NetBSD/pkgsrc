# $NetBSD: Makefile,v 1.8 2004/07/21 23:58:17 schmonz Exp $
#

DISTNAME=	qmail-users-1.0
CATEGORIES=	mail
MASTER_SITES=   #
DISTFILES=	#

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.qmail.org/
COMMENT=	Users required to build & run qmail package

NO_BUILDLINK=	# defined

PKG_GROUPS=	qmail nofiles

PKG_USERS+=	alias:nofiles::alias:${QMAILDIR}/alias
PKG_USERS+=	qmaill:nofiles::qmaill:${QMAILDIR}
PKG_USERS+=	qmaild:nofiles::qmaild:${QMAILDIR}
PKG_USERS+=	qmailp:nofiles::qmailp:${QMAILDIR}
PKG_USERS+=	qmailq:qmail::qmailq:${QMAILDIR}
PKG_USERS+=	qmailr:qmail::qmailr:${QMAILDIR}
PKG_USERS+=	qmails:qmail::qmails:${QMAILDIR}

WRKSRC=		${WRKDIR}
NO_BUILD=	YES
NO_CHECKSUM=	YES
USE_PKGINSTALL=	YES

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
