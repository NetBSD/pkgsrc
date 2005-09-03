# $NetBSD: Makefile,v 1.2 2005/09/03 06:57:14 xtraeme Exp $
#

DISTNAME=	pipebench-0.40
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.habets.pp.se/synscan/programs.php?prog=pipebench
COMMENT=	Measures the speed of a pipe

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipebench ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
