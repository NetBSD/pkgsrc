# $NetBSD: Makefile,v 1.64 2023/10/24 22:10:22 wiz Exp $

DISTNAME=	libfetch-2.39
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.FreeBSD.org/
COMMENT=	Library to access HTTP/FTP server
LICENSE=	modified-bsd

USE_FEATURES=		nbcompat

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"
.if !empty(FETCH_USING:Mfetch)
CHECK_PERMS=		no
.endif

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/cat3 ${PKGMANDIR}/man3

BUILD_TARGET=	depend all
INSTALL_TARGET=	install includes

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}
	${TOUCH} ${WRKSRC}/fetch.cat3

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
