# $NetBSD: Makefile,v 1.18 2019/04/26 13:14:07 maya Exp $

DISTNAME=	calypso-1.3
PKGREVISION=	2
CATEGORIES=	net time
MASTER_SITES=	http://keithp.com/calypso/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://keithp.com/blogs/calypso/
COMMENT=	CardDAV/CalDAV server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-vobject>=0.8.1c:../../textproc/py-vobject
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

INSTALLATION_DIRS=	share/examples/calypso
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # as of 1.3
REPLACE_PYTHON=	calypso.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/calypso.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/calypso.1
	${INSTALL_DATA} ${WRKSRC}/config ${DESTDIR}${PREFIX}/share/examples/calypso/

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
