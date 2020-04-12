# $NetBSD: Makefile,v 1.25 2020/04/12 08:27:57 adam Exp $
#

DISTNAME=	libchewing-0.4.0
PKGREVISION=	13
CATEGORIES=	chinese inputmethod
MASTER_SITES=	https://github.com/chewing/libchewing/releases/download/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
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
