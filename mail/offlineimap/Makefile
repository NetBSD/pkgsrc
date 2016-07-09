# $NetBSD: Makefile,v 1.29 2016/07/09 13:03:54 wiz Exp $


DISTNAME=	offlineimap-6.5.6
DISTFILES=	v6.5.6.tar.gz
CATEGORIES=	mail
MASTER_SITES=	https://github.com/OfflineIMAP/offlineimap/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://offlineimap.org/
COMMENT=	Powerful IMAP/Maildir synchronization and reader support
LICENSE=	python-software-foundation AND gnu-gpl-v2 # or later

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-cursespanel-[0-9]*:../../devel/py-cursespanel
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

INSTALLATION_DIRS=	share/examples/offlineimap

EGG_NAME=	${PKGNAME_NOREV}
REPLACE_PYTHON=	offlineimap/imaplib2.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 6.5.5

post-install:
.for f in offlineimap.conf offlineimap.conf.minimal
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/offlineimap/${f}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
