# $NetBSD: Makefile,v 1.1 2004/03/28 21:27:58 darcy Exp $
# FreeBSD Id: ports/devel/epydoc/Makefile,v 1.1 2003/12/29 07:07:37 ijliao Exp

DISTNAME=	epydoc-2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=epydoc/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://epydoc.sourceforge.net/
COMMENT=	Python documentation framework

USE_BUILDLINK3=     yes
PYDISTUTILSPKG=     yes

EPYDOCDIR=	${PREFIX}/share/doc/epydoc

post-install:
	cd ${WRKSRC}/doc && ${PAX} -rw -pp -pm . ${EPYDOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
