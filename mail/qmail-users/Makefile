# $NetBSD: Makefile,v 1.12 2006/04/23 00:12:38 jlam Exp $
#

DISTNAME=	qmail-users-1.0
CATEGORIES=	mail
MASTER_SITES=   #
DISTFILES=	#

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.qmail.org/
COMMENT=	Users required to build & run qmail package

PKG_INSTALLATION_TYPES=	overwrite pkgviews


PKG_GROUPS=	qmail nofiles

PKG_USERS+=	alias:nofiles
PKG_USERS+=	qmaill:nofiles
PKG_USERS+=	qmaild:nofiles
PKG_USERS+=	qmailp:nofiles
PKG_USERS+=	qmailq:qmail
PKG_USERS+=	qmailr:qmail
PKG_USERS+=	qmails:qmail

.for user in ${PKG_USERS:C/\:.*//}
PKG_GECOS.${user}=	qmail ${user} pseudo-user
PKG_HOME.${user}=	${QMAILDIR}
.endfor
PKG_HOME.alias=		${QMAILDIR}/alias

WRKSRC=		${WRKDIR}
NO_BUILD=	YES
NO_CHECKSUM=	YES

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
