# $NetBSD: Makefile,v 1.5 2025/04/03 21:04:08 pin Exp $

DISTNAME=	netop-0.1.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ZingerLittleBee/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ZingerLittleBee/netop/
COMMENT=	Network top
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
