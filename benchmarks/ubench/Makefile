# $NetBSD: Makefile,v 1.4 2005/12/27 20:51:40 reed Exp $
#

DISTNAME=	ubench-0.32
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.phystech.com/ftp/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.phystech.com/download/ubench.html
COMMENT=	The Unix Benchmark utility

BUILD_TARGET=	ubench
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/doc/ubench

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_FILES.path=	Makefile
SUBST_SED.path=		-e "s,/usr/local,${PREFIX},"

post-install:
	${INSTALL_MAN} ${WRKSRC}/ubench.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ubench

.include "../../mk/bsd.pkg.mk"
