# $NetBSD: Makefile,v 1.10 2014/10/07 16:47:12 adam Exp $
#

DISTNAME=	libchewing-0.4.0
PKGREVISION=	1
CATEGORIES=	chinese inputmethod
MASTER_SITES=	https://github.com/chewing/libchewing/releases/download/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://chewing.im/
COMMENT=	The intelligent phonetic input method library
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	yes

PKGCONFIG_OVERRIDE=	chewing.pc.in

TEST_TARGET=	check

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
