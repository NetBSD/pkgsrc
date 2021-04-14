# $NetBSD: Makefile,v 1.23 2021/04/14 10:53:47 kim Exp $

DISTNAME=	onig-6.9.7
PKGNAME=	${DISTNAME:S/onig/oniguruma/:S/-rev/pl/:S/-rc/rc/}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kkos/}
GITHUB_PROJECT=	oniguruma
GITHUB_RELEASE=	v${DISTNAME:S/onig-//:S/-/_/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kkos/oniguruma
COMMENT=	Regular expressions library
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${DISTNAME:C/-rev..*//:C/-rc..*//}

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-binary-compatible-posix-api=yes

PKGCONFIG_OVERRIDE=	oniguruma.pc.in
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
