# $NetBSD: Makefile,v 1.5 2005/03/24 21:12:52 wiz Exp $

DISTNAME=	epydoc-2.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=epydoc/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://epydoc.sourceforge.net/
COMMENT=	Python documentation framework

USE_BUILDLINK3=     yes
PYDISTUTILSPKG=     yes

EPYDOCDIR=	${PREFIX}/share/doc/epydoc

post-install:
	${INSTALL_DATA_DIR} ${EPYDOCDIR}
	cd ${WRKSRC}/doc && ${PAX} -rw -pp -pm . ${EPYDOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
