# $NetBSD: Makefile,v 1.4 2003/07/21 16:44:38 martti Exp $
#

DISTNAME=	vilearn-1.0
CATEGORIES=	editors misc
MASTER_SITES=	ftp://terminator.rs.itd.umich.edu/unix/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.umich.edu/~rsug/misc/vilearn.html
COMMENT=	Online vi tutorial, from basic to advanced

EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${SED} '1,/^wes$$/d' | ${SH}

.include "../../mk/bsd.pkg.mk"
