# $NetBSD: Makefile,v 1.16 2004/01/20 12:15:42 agc Exp $
#

DISTNAME=		incoming		# yes, really!
PKGNAME=		xgalaga-2.0.34
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xgalaga/}
EXTRACT_SUFX=		# empty

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sourceforge.net/projects/xgalaga/
COMMENT=		Very fast true-to-the-original port of galaga for X11

WRKSRC=			${WRKDIR}/${PKGNAME:C,nb${PKGREVISION},,}
USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/xgalaga
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/bin

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/xgalaga/README

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
