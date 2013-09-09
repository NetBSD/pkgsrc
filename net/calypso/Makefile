# $NetBSD: Makefile,v 1.6 2013/09/09 14:07:59 wiz Exp $

DISTNAME=	calypso-1.0
PKGREVISION=	2
CATEGORIES=	net time
MASTER_SITES=	http://keithp.com/calypso/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://keithp.com/blogs/calypso/
COMMENT=	CardDAV/CalDAV server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-vobject>=0.8.1c:../../textproc/py-vobject
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

#WRKSRC=		${WRKDIR}/calypso

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_INCLUDE_3X=	yes

INSTALLATION_DIRS=	share/examples/calypso

REPLACE_PYTHON=	calypso.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/config ${DESTDIR}${PREFIX}/share/examples/calypso/

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
