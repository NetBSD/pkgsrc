# $NetBSD: Makefile,v 1.5 2006/10/04 21:37:40 wiz Exp $
#

DISTNAME=	vilearn-1.0
CATEGORIES=	editors misc
MASTER_SITES=	ftp://terminator.rs.itd.umich.edu/unix/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://vilearn.org/
COMMENT=	Online vi tutorial, from basic to advanced

EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${SED} '1,/^wes$$/d' | ${SH}

.include "../../mk/bsd.pkg.mk"
