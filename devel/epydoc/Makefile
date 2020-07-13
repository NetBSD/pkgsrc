# $NetBSD: Makefile,v 1.29 2020/07/13 20:05:11 wiz Exp $

DISTNAME=	epydoc-3.0.1
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=epydoc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://epydoc.sourceforge.net/
COMMENT=	Python documentation framework
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 3.0.1

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/epydoc

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/epydoc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/epydocgui.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}/doc && pax -rw -pp -pm . ${DESTDIR}${PREFIX}/share/doc/epydoc

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
