# $NetBSD: Makefile,v 1.35 2024/05/29 16:33:10 adam Exp $
#

GITHUB_PROJECT=	libchewing
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
DISTNAME=	libchewing-0.5.1
PKGREVISION=	7
CATEGORIES=	chinese inputmethod
MASTER_SITES=	${MASTER_SITE_GITHUB:=chewing/}
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
