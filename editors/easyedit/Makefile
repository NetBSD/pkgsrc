# $NetBSD: Makefile,v 1.16 2013/03/30 21:57:25 dholland Exp $
#

DISTNAME=	ee-1.4.6.src
PKGNAME=	easyedit-1.4.6
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://mahon.cwx.net/sources/
EXTRACT_SUFX=	.tgz

PATCHFILES=	easyedit-jumbo-patch-20130330.gz
PATCH_SITES=	http://www.NetBSD.org/~dholland/patchkits/easyedit/
PATCH_DIST_STRIP= -p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mahon.cwx.net/
COMMENT=	Easy to use text editor with onscreen instructions

MAKE_JOBS_SAFE= 	no

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
MAKE_FILE=	make.local

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-configure:
	cd ${WRKSRC} && ./create.make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ee ${DESTDIR}${PREFIX}/bin/easyedit
	${INSTALL_MAN} ${WRKSRC}/ee.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/easyedit.1

.include "../../mk/bsd.pkg.mk"
