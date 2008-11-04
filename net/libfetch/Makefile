# $NetBSD: Makefile,v 1.23 2008/11/04 16:14:24 joerg Exp $
#

DISTNAME=	libfetch-2.20
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty

NO_CHECKSUM=	yes

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.FreeBSD.org/
COMMENT=	Library to access HTTP/FTP server
#LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES=		nbcompat

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/cat3 ${PKGMANDIR}/man3

BUILD_TARGET=	depend all
INSTALL_TARGET=	install includes

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
