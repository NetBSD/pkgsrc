# $NetBSD: Makefile,v 1.1.1.1 2000/04/01 00:21:25 dmcmahill Exp $
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin/mg
	${INSTALL_MAN} ${WRKSRC}/mg.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/mg.rc ${PREFIX}/bin/mg.rc

.include "../../mk/bsd.pkg.mk"
