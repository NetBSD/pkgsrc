# $NetBSD: Makefile,v 1.13 2009/02/07 17:33:51 abs Exp $
#

DISTNAME=	ee-1.4.6.src
PKGNAME=	easyedit-1.4.6
CATEGORIES=	editors
MASTER_SITES=	http://mahon.cwx.net/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mahon.cwx.net/
COMMENT=	Easy to use text editor with onscreen instructions

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE= 	no

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ee ${DESTDIR}${PREFIX}/bin/easyedit
	${INSTALL_MAN} ${WRKSRC}/ee.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/easyedit.1

.include "../../mk/bsd.pkg.mk"
