# $NetBSD: Makefile,v 1.24 2004/07/21 22:35:59 schmonz Exp $
#

DISTNAME=	qmail-1.03
PKGREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/			\
		ftp://ftp.ntnu.no/pub/unix/mail/qmail/		\
		ftp://ftp.jp.qmail.org/qmail/			\
		ftp://ftp.net.ohio-state.edu/pub/networking/mail/qmail/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://cr.yp.to/qmail.html
COMMENT=	Secure, reliable, efficient, simple, and fast MTA

CONFLICTS+=	netqmail-[0-9]*

USE_BUILDLINK3=	yes

RESTRICTED=	"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_PACKAGE=	"needs work to function properly as a binary package"

.include "../../mail/qmail/Makefile.common"

.include "../../mk/bsd.pkg.mk"
