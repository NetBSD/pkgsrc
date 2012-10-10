# $NetBSD: Makefile,v 1.41.8.1 2012/10/10 06:46:16 tron Exp $
#

DISTNAME=	libfetch-2.34
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.FreeBSD.org/
COMMENT=	Library to access HTTP/FTP server
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES=		nbcompat

USE_BSD_MAKEFILE=	yes

MAKE_JOBS_SAFE=		NO

.include "../../mk/bsd.prefs.mk"
.if !empty(FETCH_USING:Mfetch)
CHECK_PERMS=		no
.endif
.if ${OPSYS} == "Linux"
CFLAGS+=	-fPIC
.endif

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/cat3 ${PKGMANDIR}/man3

BUILD_TARGET=	depend all
INSTALL_TARGET=	install includes

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
