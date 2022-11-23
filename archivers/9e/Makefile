# $NetBSD: Makefile,v 1.15 2022/11/23 08:56:42 nikita Exp $

DISTNAME=	9e
PKGNAME=	9e-1.0
CATEGORIES=	archivers plan9
MASTER_SITES=	https://www.aydogan.net/distfiles/archivers/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20080929004038/http://www.eecs.harvard.edu/~wkj/Software/9e/
COMMENT=	Explode Plan9 archives

NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9e ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
