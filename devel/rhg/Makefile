# $NetBSD: Makefile,v 1.1 2026/07/01 22:04:04 wiz Exp $

DISTNAME=	mercurial-${VERSION}
PKGNAME=	rhg-${VERSION}
CATEGORIES=	devel scm
MASTER_SITES=	https://www.mercurial-scm.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/
COMMENT=	Experimental Rust version of Mercurial
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # OR newer

DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial

INSTALLATION_DIRS=	bin share/doc/rhg

WRKSRC=		${WRKDIR}/${DISTNAME}/rust

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rhg ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/rhg/README.md ${DESTDIR}${PREFIX}/share/doc/rhg

.include "../../devel/py-mercurial/version.mk"
.include "cargo-depends.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
