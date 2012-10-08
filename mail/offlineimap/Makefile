# $NetBSD: Makefile,v 1.23 2012/10/08 12:19:19 asau Exp $
#

DISTNAME=	offlineimap-v6.5.2.1
PKGNAME=	${DISTNAME:S/-v/-/}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://cloud.github.com/downloads/spaetz/offlineimap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://offlineimap.org/
COMMENT=	Powerful IMAP/Maildir synchronization and reader support
LICENSE=	python-software-foundation AND gnu-gpl-v2 # or later

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-cursespanel-[0-9]*:../../devel/py-cursespanel

WRKSRC=		${WRKDIR}/offlineimap

INSTALLATION_DIRS=	share/examples/offlineimap

EGG_NAME=	${PKGNAME_NOREV}

post-install:
.for f in offlineimap.conf offlineimap.conf.minimal
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/offlineimap/${f}
.endfor

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
