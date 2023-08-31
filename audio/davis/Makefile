# $NetBSD: Makefile,v 1.3 2023/08/31 10:13:19 pin Exp $

DISTNAME=	davis-0.1.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=SimonPersson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SimonPersson/davis/
COMMENT=	CLI client for MPD
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/davis.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/davis.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
