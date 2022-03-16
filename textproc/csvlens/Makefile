# $NetBSD: Makefile,v 1.1 2022/03/16 11:18:02 pin Exp $

DISTNAME=	csvlens-0.1.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=YS-L/}
GITHUB_PROJECT=	csvlens
GITHUB_TAG=	a239f7c0423dfb8da1a04f977975cf96b4a7180f

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/YS-L/csvlens/
COMMENT=	Command line csv viewer
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/csvlens \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
