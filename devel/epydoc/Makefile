# $NetBSD: Makefile,v 1.11 2009/03/04 13:29:43 darcy Exp $

DISTNAME=	epydoc-2.1
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=epydoc/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://epydoc.sourceforge.net/
COMMENT=	Python documentation framework

PKG_DESTDIR_SUPPORT=    user-destdir

USE_TOOLS+=	pax

PYDISTUTILSPKG=     yes

EPYDOCDIR=	${PREFIX}/share/doc/epydoc

post-install:
	${INSTALL_DATA_DIR} ${EPYDOCDIR}
	cd ${WRKSRC}/doc && pax -rw -pp -pm . ${EPYDOCDIR}

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
