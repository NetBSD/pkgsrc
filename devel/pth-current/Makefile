# $NetBSD: Makefile,v 1.10 2000/06/01 11:23:24 rh Exp $
#

DISTNAME=	pth-1.3b1
PKGNAME=	${DISTNAME:S/-/-current-/}
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/gnu/pth/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/pth/pth.html

IGNORE=         "superseded by pth package"

CONFLICTS=	pth-*

USE_PKGLIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-pthread

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pth/
	${INSTALL_DATA} ${WRKSRC}/pthread.ps ${PREFIX}/share/doc/pth/
	${INSTALL_DATA} ${WRKSRC}/rse-pmt.ps ${PREFIX}/share/doc/pth/

.include "../../mk/bsd.pkg.mk"
