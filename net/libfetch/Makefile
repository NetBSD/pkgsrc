# $NetBSD: Makefile,v 1.1.1.1 2008/02/07 01:48:22 joerg Exp $
#

DISTNAME=	libfetch-2.0
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty

NO_CHECKSUM=	yes

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.FreeBSD.org/
COMMENT=	Library to access HTTP/FTP server
#LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	lib ${PKGMANDIR}/cat3 ${PKGMANDIR}/man3

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
