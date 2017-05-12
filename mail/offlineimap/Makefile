# $NetBSD: Makefile,v 1.31 2017/05/12 10:07:41 fhajny Exp $


DISTNAME=	offlineimap-7.1.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=OfflineIMAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://offlineimap.org/
COMMENT=	Powerful IMAP/Maildir synchronization and reader support
LICENSE=	gnu-gpl-v2 # or later

GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-cursespanel-[0-9]*:../../devel/py-cursespanel
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

INSTALLATION_DIRS=	share/examples/offlineimap

EGG_NAME=	${PKGNAME_NOREV}
REPLACE_PYTHON=	offlineimap/imaplib2.py

post-install:
.for f in offlineimap.conf offlineimap.conf.minimal
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/offlineimap/${f}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
