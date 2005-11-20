# $NetBSD: Makefile,v 1.1.1.1 2005/11/20 16:58:12 xtraeme Exp $
#

DISTNAME=	f4l-0.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=f4l/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://f4l.sourceforge.net/
COMMENT=	Development environment for Macromedia Flash

NO_CONFIGURE=	yes

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/f4l ${PREFIX}/bin

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
