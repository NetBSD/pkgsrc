# $NetBSD: Makefile,v 1.3 2022/08/12 15:01:42 he Exp $

DISTNAME=	routinator-0.11.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=NLnetLabs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	routinator

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NLnetLabs/routinator
COMMENT=	Validate RPKI ROA against routing announcements
LICENSE=	modified-bsd

# 0.11.0 requires minimum this rust version:
RUST_REQ=		1.52.0

.include "cargo-depends.mk"

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${DOCDIR} ${EGDIR}

.include "../../mk/bsd.prefs.mk"

# toolchain/54192, induces rtld issues
.if ${OPSYS} == "NetBSD"
MAKE_JOBS_SAFE=	no
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/cargo \
		build --locked --frozen \
		-j ${_MAKE_JOBS_N}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/debug/routinator \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/routinator.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/./etc/routinator.conf.example \
		${DESTDIR}${EGDIR}

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
