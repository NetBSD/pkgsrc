# $NetBSD: Makefile,v 1.46 2013/01/26 21:38:45 adam Exp $

DISTNAME=	xpp-1.5
PKGREVISION=	8
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cups/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cups.sourceforge.net/xpp/index.html
COMMENT=	X Printing Panel

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

DOCDIR=		${PREFIX}/share/doc/xpp

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} LICENSE README ${DESTDIR}${DOCDIR}

.include "../../print/cups/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
