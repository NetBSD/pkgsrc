# $NetBSD: Makefile,v 1.12 2006/03/04 21:30:23 jlam Exp $
#

DISTNAME=	fnet.pl-1.4
PKGNAME=	pfnet-1.4
PKGREVISION=	1
CATEGORIES=	chat net
MASTER_SITES=	ftp://ftp.abattoir.com/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.abattoir.com/~banshee/Tech/
COMMENT=	Minimal FNET-like ICB client written in Perl

WRKSRC=		${WRKDIR}/fnet-1.4
USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	bin

do-build:
	${SED} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/fnet.pl >${WRKSRC}/pfnet

do-install:
	${INSTALL_DATA_DIR} ${PERL5_INSTALLVENDORLIB}
	${INSTALL_DATA} ${WRKSRC}/CMDLINE.pm ${WRKSRC}/FNET.pm		\
		${PERL5_INSTALLVENDORLIB}
	${INSTALL_SCRIPT} ${WRKSRC}/pfnet ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
