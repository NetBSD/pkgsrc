# $NetBSD: Makefile,v 1.2 2000/07/11 10:03:50 agc Exp $
#

DISTNAME=	9.01
PKGNAME=	xrn-9.01
CATEGORIES=	news x11
MASTER_SITES=	ftp://sipb.mit.edu/pub/xrn/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mit.edu/people/jik/software/xrn.html

DIST_SUBDIR=	xrn

USE_IMAKE=	yes
NO_WRKSUBDIR=	yes

pre-install:
	${MKDIR} ${X11PREFIX}/share/doc/xrn
	for f in COMMON-PROBLMS COPYRIGHT CREDITS ChangeLog; do		\
		${INSTALL_DATA} ${WRKSRC}/$$f ${X11PREFIX}/share/doc/xrn; \
	done

.include "../../mk/bsd.pkg.mk"
