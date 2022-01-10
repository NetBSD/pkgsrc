# $NetBSD: Makefile,v 1.38 2022/01/10 08:30:00 wiz Exp $

DISTNAME=	offlineimap-7.3.4
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=OfflineIMAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://offlineimap.org/
COMMENT=	Powerful IMAP/Maildir synchronization and reader support
LICENSE=	gnu-gpl-v2 # or later

GITHUB_TAG=	v${PKGVERSION_NOREV}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-cursespanel-[0-9]*:../../devel/py-cursespanel
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

INSTALLATION_DIRS=	share/examples/offlineimap

EGG_NAME=	${PKGNAME_NOREV}

post-install:
.for f in offlineimap.conf offlineimap.conf.minimal
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/offlineimap/${f}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
