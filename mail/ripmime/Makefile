# $NetBSD: Makefile,v 1.7 2009/06/30 00:07:19 joerg Exp $
#

DISTNAME=	ripmime-1.4.0.2
CATEGORIES=	mail
MASTER_SITES=	http://www.pldaniels.com/ripmime/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.pldaniels.com/ripmime/
COMMENT=	Extract the attached files out of a MIME encoded email package

PKGMANDIR?=	man
MAKE_ENV+=	PKGMANDIR=${PKGMANDIR:Q}
INSTALLATION_DIRS=	bin ${PKGMANDIR}

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.pkg.mk"
