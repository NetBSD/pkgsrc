# $NetBSD: Makefile,v 1.10 2003/12/13 00:45:23 wiz Exp $
#

DISTNAME=		gice-0.6.1
PKGREVISION=		4
WRKSRC=			${WRKDIR}/gice
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gice/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://gice.sourceforge.net/
COMMENT=		Powerful C text editor with advanced features

USE_X11=		YES
USE_GMAKE=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

ALL_TARGET=		gice

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gice ${PREFIX}/bin

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
