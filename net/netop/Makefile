# $NetBSD: Makefile,v 1.1 2022/06/18 10:05:58 pin Exp $

DISTNAME=	netop-0.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ZingerLittleBee/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ZingerLittleBee/netop/
COMMENT=	Network top
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/netop \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
