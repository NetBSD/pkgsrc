# $NetBSD: Makefile,v 1.22 2025/11/27 08:56:46 wiz Exp $

DISTNAME=	cd-discid-1.4
CATEGORIES=	audio
#MASTER_SITES=	http://linukz.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/taem/cd-discid
COMMENT=	Read CD to obtain CDDB discid information
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cd-discid ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cd-discid.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
