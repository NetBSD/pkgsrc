# $NetBSD: Makefile,v 1.8 2010/02/04 02:39:54 joerg Exp $
#

DISTNAME=	ripmime-1.4.0.2
CATEGORIES=	mail
MASTER_SITES=	http://www.pldaniels.com/ripmime/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.pldaniels.com/ripmime/
COMMENT=	Extract the attached files out of a MIME encoded email package

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ripmime ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ripmime.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
