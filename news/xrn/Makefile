# $NetBSD: Makefile,v 1.1 1998/08/29 21:54:49 frueauf Exp $
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
	${MKDIR} ${X11BASE}/share/doc/xrn
.for file in COMMON-PROBLMS COPYRIGHT CREDITS ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${file} ${X11BASE}/share/doc/xrn
.endfor

.include "../../mk/bsd.pkg.mk"
