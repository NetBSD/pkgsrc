# $NetBSD: Makefile,v 1.4 2023/12/18 11:07:58 pin Exp $

DISTNAME=	netop-0.1.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ZingerLittleBee/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/ZingerLittleBee/netop/
COMMENT=	Network top
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
