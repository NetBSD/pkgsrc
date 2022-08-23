# $NetBSD: Makefile,v 1.27 2022/08/23 21:49:55 wiz Exp $

DISTNAME=	xmpppy-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=xmpppy/}
GITHUB_PROJECT=	xmpppy

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://xmpppy.sourceforge.net/
COMMENT=	XMPP (Jabber) library for Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-expat>=0nb4:../../textproc/py-expat

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	dns

USE_PKG_RESOURCES=	yes

DOCDIR=		${PREFIX}/share/doc/py-xmpppy
EXDIR=		${PREFIX}/share/examples/py-xmpppy

INSTALLATION_DIRS+=	${DOCDIR} ${EXDIR}

post-install:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${EXDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/docs/examples/*.py \
		${DESTDIR}${EXDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html \
		${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.png \
		${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.css \
		${DESTDIR}${DOCDIR}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
