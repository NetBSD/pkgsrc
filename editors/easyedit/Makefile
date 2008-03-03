# $NetBSD: Makefile,v 1.12 2008/03/03 18:25:52 jlam Exp $
#

DISTNAME=	ee-1.4.6.src
PKGNAME=	easyedit-1.4.6
CATEGORIES=	editors
MASTER_SITES=	http://mahon.cwx.net/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mahon.cwx.net/
COMMENT=	Easy to use text editor

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ee ${DESTDIR}${PREFIX}/bin/easyedit
	${INSTALL_MAN} ${WRKSRC}/ee.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/easyedit.1

.include "../../mk/bsd.pkg.mk"
