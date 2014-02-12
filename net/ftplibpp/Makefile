# $NetBSD: Makefile,v 1.13 2014/02/12 23:18:20 tron Exp $
#

DISTNAME=		ftplibpp-1.0.1
PKGREVISION=		4
CATEGORIES=		net devel
MASTER_SITES=		http://download.berlios.de/kasablanca/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kasablanca.berlios.de/ftplibpp/
COMMENT=		C++ class providing ftp client functionality

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	include lib share/doc/ftplibpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/ftplibpp.html ${DESTDIR}${PREFIX}/share/doc/ftplibpp

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
