# $NetBSD: Makefile,v 1.9 2005/06/17 03:50:27 jlam Exp $
#

DISTNAME=	fnet.pl-1.4
PKGNAME=	pfnet-1.4
CATEGORIES=	chat net
MASTER_SITES=	ftp://ftp.abattoir.com/pub/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.abattoir.com/~banshee/Tech/
COMMENT=	Minimal FNET-like ICB client written in Perl

WRKSRC=		${WRKDIR}/fnet-1.4
USE_PERL5=	# defined

INSTALLATION_DIRS=	bin

do-build:
	${SED} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/fnet.pl >${WRKSRC}/pfnet

do-install:
	${INSTALL_DATA_DIR} ${PERL5_SITELIB}
	${INSTALL_DATA} ${WRKSRC}/CMDLINE.pm ${WRKSRC}/FNET.pm ${PERL5_SITELIB}
	${INSTALL_SCRIPT} ${WRKSRC}/pfnet ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
