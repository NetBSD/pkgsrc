# $NetBSD: Makefile,v 1.3 2001/01/10 11:57:50 tron Exp $

DISTNAME=	gzip-1.2.4a
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html

DEPENDS+=	gzip-base-1.2.4a:../../archivers/gzip-base
DEPENDS+=	gzip-info-1.2.4a:../../archivers/gzip-info

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.if exists(/usr/bin/gzip)
IGNORE=		"${PKGNAME} is part of your ${OPSYS} distribution"
.endif

.include "../../mk/bsd.pkg.mk"
