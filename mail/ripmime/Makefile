# $NetBSD: Makefile,v 1.3 2005/01/04 14:51:05 wiz Exp $
#

DISTNAME=       ripmime-1.4.0.2
CATEGORIES=	mail
MASTER_SITES=	http://www.pldaniels.com/ripmime/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.pldaniels.com/ripmime/
COMMENT=	Extract the attached files out of a MIME encoded email package

PKGMANDIR?=	man
MAKE_ENV+=	PKGMANDIR=${PKGMANDIR}
INSTALLATION_DIRS=	bin ${PKGMANDIR}

USE_BUILDLINK3=	YES

.include "../../mk/bsd.pkg.mk"
