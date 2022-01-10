# $NetBSD: Makefile,v 1.23 2022/01/10 20:21:37 wiz Exp $

DISTNAME=	calypso-1.3
PKGREVISION=	4
CATEGORIES=	net time
MASTER_SITES=	http://keithp.com/calypso/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://keithp.com/blogs/calypso/
COMMENT=	CardDAV/CalDAV server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-vobject>=0.8.1c:../../textproc/py-vobject
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

INSTALLATION_DIRS=	share/examples/calypso
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

PYTHON_VERSIONS_ACCEPTED= 27 # as of 1.3
REPLACE_PYTHON=	calypso.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/calypso.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/calypso.1
	${INSTALL_DATA} ${WRKSRC}/config ${DESTDIR}${PREFIX}/share/examples/calypso/

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
