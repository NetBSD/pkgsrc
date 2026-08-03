# $NetBSD: Makefile,v 1.44 2026/08/03 10:11:58 adam Exp $

DISTNAME=	offlineimap-8.0.3
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/offlineimap/}

MAINTAINER=	me@wbrawner.com
HOMEPAGE=	https://github.com/OfflineIMAP/offlineimap3
COMMENT=	Powerful IMAP/Maildir synchronization and reader support (v3)
LICENSE=	gnu-gpl-v2 # or later

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-distro>=0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-imaplib2>=3.5:../../mail/py-imaplib2
DEPENDS+=	${PYPKGPREFIX}-rfc6555-[0-9]*:../../net/py-rfc6555
TEST_DEPENDS+=	${PYPKGPREFIX}-certifi>=2020.6.20:../../security/py-certifi
TEST_DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.25.9:../../www/py-urllib3

INSTALLATION_DIRS=	share/examples/offlineimap

post-install:
.for f in offlineimap.conf offlineimap.conf.minimal
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/offlineimap/${f}
.endfor

# as of 8.0.2
# needs imap credentials for testing:
# 1 warning, 1 error

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
