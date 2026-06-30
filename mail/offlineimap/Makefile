# $NetBSD: Makefile,v 1.43 2026/06/30 09:58:48 wiz Exp $

DISTNAME=	offlineimap3-8.0.2
PKGNAME=	${DISTNAME:S/3-/-/}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=OfflineIMAP/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	me@wbrawner.com
HOMEPAGE=	https://github.com/OfflineIMAP/offlineimap3
COMMENT=	Powerful IMAP/Maildir synchronization and reader support (v3)
LICENSE=	gnu-gpl-v2 # or later

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-rfc6555-[0-9]*:../../net/py-rfc6555
DEPENDS+=	${PYPKGPREFIX}-imaplib2>=3.5:../../mail/py-imaplib2
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.25.9:../../www/py-urllib3

INSTALLATION_DIRS=	share/examples/offlineimap

WRKSRC=		${WRKDIR}/${DISTNAME}

post-install:
.for f in offlineimap.conf offlineimap.conf.minimal
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/offlineimap/${f}
.endfor

WHEEL_NAME=	offlineimap-${PKGVERSION_NOREV}

# as of 8.0.2
# needs imap credentials for testing:
# 1 warning, 1 error

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
