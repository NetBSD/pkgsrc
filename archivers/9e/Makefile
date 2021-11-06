# $NetBSD: Makefile,v 1.14 2021/11/06 09:46:31 nia Exp $

DISTNAME=	9e
PKGNAME=	9e-1.0
CATEGORIES=	archivers plan9
MASTER_SITES=	https://www.aydogan.net/distfiles/archivers/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bebik.net/doku.php?id=software:9e
COMMENT=	Explode Plan9 archives

NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9e ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
