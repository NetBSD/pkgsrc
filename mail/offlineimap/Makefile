# $NetBSD: Makefile,v 1.42 2024/08/14 17:25:21 wiz Exp $

DISTNAME=	offlineimap-7.3.4
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=OfflineIMAP/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://offlineimap.org/
COMMENT=	Powerful IMAP/Maildir synchronization and reader support
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	${PYPKGPREFIX}-rfc6555-[0-9]*:../../net/py-rfc6555
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

INSTALLATION_DIRS=	share/examples/offlineimap

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported

EGG_NAME=	${PKGNAME_NOREV}

post-install:
.for f in offlineimap.conf offlineimap.conf.minimal
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/offlineimap/${f}
.endfor

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
