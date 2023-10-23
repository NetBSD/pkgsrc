# $NetBSD: Makefile,v 1.41 2023/10/23 06:37:48 wiz Exp $

DISTNAME=	offlineimap-7.3.4
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=OfflineIMAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://offlineimap.org/
COMMENT=	Powerful IMAP/Maildir synchronization and reader support
LICENSE=	gnu-gpl-v2 # or later

GITHUB_TAG=	v${PKGVERSION_NOREV}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

INSTALLATION_DIRS=	share/examples/offlineimap

EGG_NAME=	${PKGNAME_NOREV}

post-install:
.for f in offlineimap.conf offlineimap.conf.minimal
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/offlineimap/${f}
.endfor

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
