# $NetBSD: Makefile,v 1.2 2000/08/27 07:11:19 jlam Exp $
#

DISTNAME=	fnet.pl-1.4
PKGNAME=	pfnet-1.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.abattoir.com/pub/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.abattoir.com/~banshee/Tech/

USE_PERL5=	# defined

WRKSRC=		${WRKDIR}/fnet-1.4

do-build:
	${SED} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/fnet.pl >${WRKSRC}/pfnet

do-install:
	${INSTALL_DATA_DIR} ${PERL5_SITELIB}
	${INSTALL_DATA} ${WRKSRC}/CMDLINE.pm ${WRKSRC}/FNET.pm ${PERL5_SITELIB}
	${INSTALL_SCRIPT} ${WRKSRC}/pfnet ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
