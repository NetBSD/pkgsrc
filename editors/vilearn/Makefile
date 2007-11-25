# $NetBSD: Makefile,v 1.6 2007/11/25 11:46:59 wiz Exp $
#

DISTNAME=	vilearn-1.0
CATEGORIES=	editors misc
MASTER_SITES=	#
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://vilearn.org/
COMMENT=	Online vi tutorial, from basic to advanced

EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${SED} '1,/^wes$$/d' | ${SH}

.include "../../mk/bsd.pkg.mk"
