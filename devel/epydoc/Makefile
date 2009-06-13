# $NetBSD: Makefile,v 1.13 2009/06/13 06:46:42 rillig Exp $

DISTNAME=	epydoc-2.1
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=epydoc/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://epydoc.sourceforge.net/
COMMENT=	Python documentation framework

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

PYDISTUTILSPKG=     yes

INSTALLATION_DIRS=	share/doc/epydoc

post-install:
	cd ${WRKSRC}/doc && \
	    pax -rw -pp -pm . ${DESTDIR}${PREFIX}/share/doc/epydoc

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
