# $NetBSD: Makefile,v 1.5 2003/06/02 01:17:48 jschauma Exp $
#

DISTNAME=	fnet.pl-1.4
PKGNAME=	pfnet-1.4
WRKSRC=		${WRKDIR}/fnet-1.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.abattoir.com/pub/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.abattoir.com/~banshee/Tech/
COMMENT=	Minimal FNET-like ICB client written in Perl

USE_PERL5=	# defined

do-build:
	${SED} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/fnet.pl >${WRKSRC}/pfnet

do-install:
	${INSTALL_DATA_DIR} ${PERL5_SITELIB}
	${INSTALL_DATA} ${WRKSRC}/CMDLINE.pm ${WRKSRC}/FNET.pm ${PERL5_SITELIB}
	${INSTALL_SCRIPT} ${WRKSRC}/pfnet ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
