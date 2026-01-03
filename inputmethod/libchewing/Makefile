# $NetBSD: Makefile,v 1.40 2026/01/03 07:40:15 wiz Exp $

GITHUB_PROJECT=	libchewing
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
DISTNAME=	libchewing-0.5.1
PKGREVISION=	11
CATEGORIES=	chinese inputmethod
MASTER_SITES=	${MASTER_SITE_GITHUB:=chewing/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://chewing.im/
COMMENT=	The intelligent phonetic input method library
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	yes

PKGCONFIG_OVERRIDE=	chewing.pc.in

TEST_TARGET=	check

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
