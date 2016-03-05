# $NetBSD: Makefile,v 1.15 2016/03/05 11:29:04 jperkin Exp $
#

DISTNAME=		ftplibpp-1.0.1
PKGREVISION=		5
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
