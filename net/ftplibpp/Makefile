# $NetBSD: Makefile,v 1.17 2023/10/24 22:10:16 wiz Exp $
#

DISTNAME=		ftplibpp-1.0.1
PKGREVISION=		7
CATEGORIES=		net devel
MASTER_SITES=		http://download.berlios.de/kasablanca/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/mkulke/ftplibpp
COMMENT=		C++ class providing ftp client functionality

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	include lib share/doc/ftplibpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/ftplibpp.html ${DESTDIR}${PREFIX}/share/doc/ftplibpp

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
