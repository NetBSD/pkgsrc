# $NetBSD: Makefile,v 1.25 2004/08/02 03:57:17 schmonz Exp $
#

PKGNAME=	${QMAIL_VERS}
PKGREVISION=	8
CATEGORIES=	mail

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://cr.yp.to/qmail.html
COMMENT=	Secure, reliable, efficient, simple, and fast MTA

CONFLICTS+=	netqmail-[0-9]*

USE_BUILDLINK3=	yes

RESTRICTED=	"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_PACKAGE=	"needs work to function properly as a binary package"

APPLY_NETQMAIL=	${DO_NADA}

.include "../../mail/qmail/Makefile.common"

.include "../../mk/bsd.pkg.mk"
