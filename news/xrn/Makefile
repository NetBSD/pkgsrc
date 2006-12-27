# $NetBSD: Makefile,v 1.14 2006/12/27 13:37:39 joerg Exp $
#

DISTNAME=	9.01
PKGNAME=	xrn-9.01
PKGREVISION=	2
CATEGORIES=	news x11
MASTER_SITES=	ftp://sipb.mit.edu/pub/xrn/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
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

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
