# $NetBSD: Makefile,v 1.6 2012/09/11 22:37:14 asau Exp $
#

DISTNAME=	pipebench-0.40
CATEGORIES=	benchmarks
MASTER_SITES=	# ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.habets.pp.se/synscan/programs.php?prog=pipebench
COMMENT=	Measures the speed of a pipe

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipebench ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
