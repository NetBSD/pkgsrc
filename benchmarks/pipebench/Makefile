# $NetBSD: Makefile,v 1.7 2026/01/22 08:40:29 wiz Exp $

DISTNAME=	pipebench-0.40
CATEGORIES=	benchmarks
MASTER_SITES=	# ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.habets.pp.se/synscan/programs_pipebench.html
COMMENT=	Measures the speed of a pipe

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipebench ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
