# $NetBSD: Makefile,v 1.3 2003/07/17 21:35:09 grant Exp $
#

DISTNAME=	vilearn-1.0
CATEGORIES=	editors misc
MASTER_SITES=	ftp://terminator.rs.itd.umich.edu/unix/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.umich.edu/~rsug/misc/vilearn.html
COMMENT=	online vi tutorial, from basic to advanced

EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${SED} '1,/^wes$$/d' | ${SH}

.include "../../mk/bsd.pkg.mk"
