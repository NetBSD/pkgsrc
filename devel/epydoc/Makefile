# $NetBSD: Makefile,v 1.8 2006/11/15 01:16:39 wulf Exp $

DISTNAME=	epydoc-2.1
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=epydoc/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://epydoc.sourceforge.net/
COMMENT=	Python documentation framework

PYDISTUTILSPKG=     yes

EPYDOCDIR=	${PREFIX}/share/doc/epydoc

post-install:
	${INSTALL_DATA_DIR} ${EPYDOCDIR}
	cd ${WRKSRC}/doc && ${PAX} -rw -pp -pm . ${EPYDOCDIR}

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
