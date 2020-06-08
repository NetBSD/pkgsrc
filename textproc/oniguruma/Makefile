# $NetBSD: Makefile,v 1.16 2020/06/08 11:26:32 adam Exp $

DISTNAME=	onig-6.9.5_rev1
PKGNAME=	${DISTNAME:S/onig/oniguruma/:S/_rev/./}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kkos/}
GITHUB_PROJECT=	oniguruma
GITHUB_RELEASE=	v${DISTNAME:S/onig-//}
#GITHUB_RELEASE=v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kkos/oniguruma
COMMENT=	Regular expressions library
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${DISTNAME:S/_rev1//}

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	oniguruma.pc.in
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
