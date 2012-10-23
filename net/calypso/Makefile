# $NetBSD: Makefile,v 1.5 2012/10/23 17:18:13 asau Exp $

DISTNAME=	calypso-1.0
PKGREVISION=	1
CATEGORIES=	net time
MASTER_SITES=	http://keithp.com/calypso/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://keithp.com/blogs/calypso/
COMMENT=	CardDAV/CalDAV server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-vobject>=0.8.1c:../../textproc/py-vobject
DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base

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
