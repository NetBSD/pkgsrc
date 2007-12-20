# $NetBSD: Makefile,v 1.8 2007/12/20 15:11:06 obache Exp $
#

DISTNAME=		ftplibpp-1.0.1
PKGREVISION=		1
CATEGORIES=		net devel
MASTER_SITES=		http://download.berlios.de/kasablanca/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kasablanca.berlios.de/ftplibpp/
COMMENT=		C++ class providing ftp client functionality

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	include lib share/doc/ftplibpp

PKG_DESTDIR_SUPPORT=	user-destdir

post-install:
	${INSTALL_DATA} ${WRKSRC}/ftplibpp.html ${DESTDIR}${PREFIX}/share/doc/ftplibpp

.include "../../mk/bsd.pkg.mk"
