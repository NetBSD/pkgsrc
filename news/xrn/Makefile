# $NetBSD: Makefile,v 1.3 2001/02/17 17:54:53 wiz Exp $
#

DISTNAME=	9.01
PKGNAME=	xrn-9.01
CATEGORIES=	news x11
MASTER_SITES=	ftp://sipb.mit.edu/pub/xrn/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mit.edu/people/jik/software/xrn.html
COMMENT=	Usenet News reader for the X window system

DIST_SUBDIR=	xrn

USE_IMAKE=	yes
NO_WRKSUBDIR=	yes

pre-install:
	${MKDIR} ${X11PREFIX}/share/doc/xrn
	for f in COMMON-PROBLMS COPYRIGHT CREDITS ChangeLog; do		\
		${INSTALL_DATA} ${WRKSRC}/$$f ${X11PREFIX}/share/doc/xrn; \
	done

.include "../../mk/bsd.pkg.mk"
