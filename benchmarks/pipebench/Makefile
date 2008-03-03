# $NetBSD: Makefile,v 1.4 2008/03/03 00:51:44 jlam Exp $
#

DISTNAME=	pipebench-0.40
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.habets.pp.se/synscan/programs.php?prog=pipebench
COMMENT=	Measures the speed of a pipe

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipebench ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
