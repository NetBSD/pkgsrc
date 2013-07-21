# $NetBSD: Makefile,v 1.10 2013/07/21 10:58:49 shattered Exp $
#

DISTNAME=	ripmime-1.4.0.10
CATEGORIES=	mail
MASTER_SITES=	http://www.pldaniels.com/ripmime/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.pldaniels.com/ripmime/
COMMENT=	Extract the attached files out of a MIME encoded email package

MAKE_JOBS_SAFE=		no

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ripmime ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ripmime.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
