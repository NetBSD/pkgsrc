# $NetBSD: Makefile,v 1.39 2025/01/27 19:12:38 rillig Exp $

DISTNAME=	gzip-1.12
CATEGORIES=	archivers
#MASTER_SITES=	${MASTER_SITE_GNU:=gzip/}
MASTER_SITES=	${MASTER_SITE_LOCAL}
#EXTRACT_SUFX=	.tar.xz
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/gzip/gzip.html
COMMENT=	Compress or expand files
LICENSE=	gnu-gpl-v3

CONFLICTS+=		gzip-base-[0-9]* gzip-info-[0-9]*

GNU_CONFIGURE=	yes
MAKE_FLAGS+=	manlinks=so
INFO_FILES=	yes
CHECK_PERMS=	no	# can't depend on checkperms; its distfile is gzipped

.include "../../mk/bsd.pkg.mk"
