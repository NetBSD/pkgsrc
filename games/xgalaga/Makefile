# $NetBSD: Makefile,v 1.14 2003/09/10 13:03:42 hubertf Exp $
#

DISTNAME=		incoming		# yes, really!
PKGNAME=		xgalaga-2.0.34
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xgalaga/}
EXTRACT_SUFX=		# empty

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sourceforge.net/projects/xgalaga/
COMMENT=		Very fast true-to-the-original port of galaga for X11

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/xgalaga
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/bin

WRKSRC=			${WRKDIR}/${PKGNAME:C,nb${PKGREVISION},,}

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${X11PREFIX}/share/xgalaga/README

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
