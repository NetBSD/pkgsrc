# $NetBSD: Makefile,v 1.1.1.1 1998/11/22 22:30:07 tv Exp $
#

DISTNAME=	fnet.pl-1.4
PKGNAME=	pfnet-1.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.abattoir.com/pub/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.abattoir.com/~banshee/Tech/

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/fnet-1.4

do-build:
	${SED} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/fnet.pl >${WRKSRC}/pfnet

do-install:
	${INSTALL_DATA} ${WRKSRC}/CMDLINE.pm ${WRKSRC}/FNET.pm \
		${PREFIX}/lib/perl5/site_perl/
	${INSTALL_SCRIPT} ${WRKSRC}/pfnet ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
