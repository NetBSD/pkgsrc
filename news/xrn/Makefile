# $NetBSD: Makefile,v 1.7 2003/03/29 12:42:08 jmmv Exp $
#

DISTNAME=	9.01
PKGNAME=	xrn-9.01
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	news x11
MASTER_SITES=	ftp://sipb.mit.edu/pub/xrn/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mit.edu/people/jik/software/xrn.html
COMMENT=	Usenet News reader for the X window system

DIST_SUBDIR=	xrn

USE_IMAKE=	yes

pre-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/doc/xrn
	for f in COMMON-PROBLMS COPYRIGHT CREDITS ChangeLog; do		\
		${INSTALL_DATA} ${WRKSRC}/$$f ${X11PREFIX}/share/doc/xrn; \
	done

.include "../../mk/bsd.pkg.mk"
