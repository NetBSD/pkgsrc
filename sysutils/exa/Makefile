# $NetBSD: Makefile,v 1.6 2021/04/07 11:38:11 fox Exp $

DISTNAME=	exa-0.10.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ogham/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGBASE}
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://the.exa.website/
COMMENT=	Replacement for ls(1) written in Rust
LICENSE=	mit

USE_LANGUAGES=	c

CARGO_CRATE_DEPENDS+=	ansi_term-0.12.1
CARGO_CRATE_DEPENDS+=	autocfg-1.0.1
CARGO_CRATE_DEPENDS+=	bitflags-1.2.1
CARGO_CRATE_DEPENDS+=	byteorder-1.3.4
CARGO_CRATE_DEPENDS+=	cc-1.0.61
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.10
CARGO_CRATE_DEPENDS+=	datetime-0.5.2
CARGO_CRATE_DEPENDS+=	git2-0.13.11
CARGO_CRATE_DEPENDS+=	glob-0.3.0
CARGO_CRATE_DEPENDS+=	hermit-abi-0.1.17
CARGO_CRATE_DEPENDS+=	idna-0.2.0
CARGO_CRATE_DEPENDS+=	jobserver-0.1.21
CARGO_CRATE_DEPENDS+=	lazy_static-1.4.0
CARGO_CRATE_DEPENDS+=	libc-0.2.79
CARGO_CRATE_DEPENDS+=	libgit2-sys-0.12.14+1.1.0
CARGO_CRATE_DEPENDS+=	libz-sys-1.1.2
CARGO_CRATE_DEPENDS+=	locale-0.2.2
CARGO_CRATE_DEPENDS+=	log-0.4.11
CARGO_CRATE_DEPENDS+=	matches-0.1.8
CARGO_CRATE_DEPENDS+=	natord-1.0.9
CARGO_CRATE_DEPENDS+=	num_cpus-1.13.0
CARGO_CRATE_DEPENDS+=	number_prefix-0.4.0
CARGO_CRATE_DEPENDS+=	openssl-src-111.12.0+1.1.1h
CARGO_CRATE_DEPENDS+=	openssl-sys-0.9.58
CARGO_CRATE_DEPENDS+=	pad-0.1.6
CARGO_CRATE_DEPENDS+=	percent-encoding-2.1.0
CARGO_CRATE_DEPENDS+=	pkg-config-0.3.19
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.57
CARGO_CRATE_DEPENDS+=	scoped_threadpool-0.1.9
CARGO_CRATE_DEPENDS+=	term_grid-0.1.7
CARGO_CRATE_DEPENDS+=	term_size-0.3.2
CARGO_CRATE_DEPENDS+=	tinyvec-0.3.4
CARGO_CRATE_DEPENDS+=	unicode-bidi-0.3.4
CARGO_CRATE_DEPENDS+=	unicode-normalization-0.1.13
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.8
CARGO_CRATE_DEPENDS+=	url-2.1.1
CARGO_CRATE_DEPENDS+=	users-0.11.0
CARGO_CRATE_DEPENDS+=	vcpkg-0.2.10
CARGO_CRATE_DEPENDS+=	winapi-0.3.9
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	zoneinfo_compiled-0.5.1

INSTALLATION_DIRS=	bin \
			${PKGMANDIR}/man1 \
			${PKGMANDIR}/man5 \
			share/bash-completion/completions \
			share/fish/vendor_completions.d \
			share/zsh/site-functions

post-build:
	${CP} ${FILESDIR}/exa.1 ${WRKDIR}/exa.1
	${CP} ${FILESDIR}/exa_colors.5 ${WRKDIR}/exa_colors.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/exa ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/exa.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/exa_colors.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/completions/completions.bash \
			${DESTDIR}${PREFIX}/share/bash-completion/completions/exa
	${INSTALL_DATA} ${WRKSRC}/completions/completions.fish \
			${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/exa.fish
	${INSTALL_DATA} ${WRKSRC}/completions/completions.zsh \
			${DESTDIR}${PREFIX}/share/zsh/site-functions/_exa


.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
