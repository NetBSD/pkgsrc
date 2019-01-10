# $NetBSD: Makefile,v 1.36 2019/01/10 06:47:42 gutteridge Exp $

DISTNAME=	gzip-1.10
CATEGORIES=	archivers
#MASTER_SITES=	${MASTER_SITE_GNU:=gzip/}
#EXTRACT_SUFX=	.tar.xz
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	Compress or expand files
LICENSE=	gnu-gpl-v3

CONFLICTS+=		gzip-base-[0-9]* gzip-info-[0-9]*

GNU_CONFIGURE=	yes
MAKE_FLAGS+=	manlinks=so
INFO_FILES=	yes
CHECK_PERMS=	no	# can't depend on checkperms; its distfile is gzipped

#bug 20453 in bug-gzip list, passed onto gnulib
CONFIGURE_ENV.AIX+=	ac_cv_header_wctype_h=no

.include "../../mk/bsd.pkg.mk"
