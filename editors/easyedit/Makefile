# $NetBSD: Makefile,v 1.11 2007/01/07 09:13:52 rillig Exp $
#

DISTNAME=	ee-1.4.6.src
PKGNAME=	easyedit-1.4.6
CATEGORIES=	editors
MASTER_SITES=	http://mahon.cwx.net/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mahon.cwx.net/
COMMENT=	Easy to use text editor

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ee ${PREFIX}/bin/easyedit
	${INSTALL_MAN} ${WRKSRC}/ee.1 ${PREFIX}/${PKGMANDIR}/man1/easyedit.1

.include "../../mk/bsd.pkg.mk"
