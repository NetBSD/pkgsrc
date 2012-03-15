# $NetBSD: Makefile,v 1.16 2012/03/15 11:53:24 obache Exp $

DISTNAME=	epydoc-2.1
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=epydoc/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://epydoc.sourceforge.net/
COMMENT=	Python documentation framework
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	#none
USE_TOOLS+=	pax

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/epydoc

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/epydoc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/epydocgui.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}/doc && \
	    pax -rw -pp -pm . ${DESTDIR}${PREFIX}/share/doc/epydoc

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
