# $NetBSD: Makefile,v 1.11 2005/06/17 04:49:47 jlam Exp $
#

DISTNAME=	9.01
PKGNAME=	xrn-9.01
PKGREVISION=	1
CATEGORIES=	news x11
MASTER_SITES=	ftp://sipb.mit.edu/pub/xrn/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mit.edu/people/jik/software/xrn.html
COMMENT=	Usenet News reader for the X window system

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	xrn

USE_IMAKE=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xrn
	for f in COMMON-PROBLMS COPYRIGHT CREDITS ChangeLog; do		\
		${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/xrn;	\
	done

.include "../../mk/bsd.pkg.mk"
