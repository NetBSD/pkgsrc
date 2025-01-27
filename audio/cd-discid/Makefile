# $NetBSD: Makefile,v 1.20 2025/01/27 20:21:13 rillig Exp $

DISTNAME=	cd-discid-1.4
CATEGORIES=	audio
MASTER_SITES=	http://linukz.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linukz.org/cd-discid.shtml
COMMENT=	Read CD to obtain CDDB discid information
LICENSE=	gnu-gpl-v2

NOT_FOR_PLATFORM=	Interix-*-*

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cd-discid ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cd-discid.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
