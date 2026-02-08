# $NetBSD: Makefile,v 1.38 2026/02/08 01:15:59 gdt Exp $

DISTNAME=	xmpppy-0.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=xmpppy/}
GITHUB_PROJECT=	xmpppy

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://xmpppy.sourceforge.net/
COMMENT=	XMPP (Jabber) library for Python
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

DOCDIR=		${PREFIX}/share/doc/py-xmpppy
EXDIR=		${PREFIX}/share/examples/py-xmpppy

INSTALLATION_DIRS+=	${DOCDIR} ${EXDIR}

.include "../../lang/python/pyversion.mk"

# Upstream says install_requires, but it is used at runtime.
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns

TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

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

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
