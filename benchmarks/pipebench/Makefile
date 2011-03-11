# $NetBSD: Makefile,v 1.5 2011/03/11 10:33:21 zafer Exp $
#

DISTNAME=	pipebench-0.40
CATEGORIES=	benchmarks
MASTER_SITES=	# ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.habets.pp.se/synscan/programs.php?prog=pipebench
COMMENT=	Measures the speed of a pipe

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipebench ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
