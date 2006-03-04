# $NetBSD: Makefile,v 1.5 2006/03/04 21:29:01 jlam Exp $
#

DISTNAME=	ubench-0.32
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.phystech.com/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
