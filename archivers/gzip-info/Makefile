# $NetBSD: Makefile,v 1.1.1.1 1999/09/18 14:26:52 kim Exp $
#

DISTNAME=	gzip-1.2.4a
PKGNAME=	gzip-info-1.2.4a
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.shar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html

EXTRACT_CMD=	${CAT} ${DOWNLOADED_DISTFILE} | ${TR} -d \\r | ${SH}

USE_GTEXINFO=	yes
INFO_FILES=	gzip.info

NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

.if exists(/usr/bin/gzip)
IGNORE=		"is part of your NetBSD distribution"
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/gzip.info ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
