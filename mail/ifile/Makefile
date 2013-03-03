# $NetBSD: Makefile,v 1.16 2013/03/03 10:59:08 shattered Exp $
#

DISTNAME=	ifile-1.3.8
CATEGORIES=	mail
MASTER_SITES=	http://qwone.com/~jason/ifile/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://qwone.com/~jason/ifile/
COMMENT=	Intelligent mail filtering system

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifile ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ifile.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
