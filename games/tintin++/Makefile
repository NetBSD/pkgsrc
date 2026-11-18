# $NetBSD: Makefile,v 1.1 2026/11/18 02:18:29 ktnb Exp $

DISTNAME=	tintin-2.02.61
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=scandum/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/scandum/tintin/
COMMENT=	Free Mud client for Android, iOS, Linux, Mac OS X and Windows
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/tt/src
GNU_CONFIGURE=	yes

.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
