# $NetBSD: Makefile,v 1.4 1998/08/20 15:17:16 tsarna Exp $
# FreeBSD Id: Makefile,v 1.17 1998/04/26 18:47:12 peter Exp 
#

DISTNAME=       gated-3-5-9
PKGNAME=        gated-3.5.9
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.gated.merit.edu/net-research/gated/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gated.org/

MIRROR_DISTFILE=	no

ALL_TARGET=	gated

post-extract:
	@${SED} -e 's#@PREFIX@#${PREFIX}#' <${FILESDIR}/configuration \
	    >${WRKSRC}/src/configs/netbsd

.include "../../mk/bsd.pkg.mk"
