# $NetBSD: Makefile,v 1.2 2000/04/01 00:30:53 dmcmahill Exp $
# Top level for mg2a package make... nothing unusual
# in this package - john refling
#

DISTNAME=       mg2a
PKGNAME=	mg2a-1.10
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.wustl.edu/languages/c/unix-c/editors/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	refling@comet.lbl.gov

USE_CONFIGURE=	NO

post-extract:
	cd ${WRKSRC} ; ${CP} sys/bsd/Makefile .

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin/mg
	${INSTALL_MAN} ${WRKSRC}/mg.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/mg.rc ${PREFIX}/bin/mg.rc

.include "../../mk/bsd.pkg.mk"
