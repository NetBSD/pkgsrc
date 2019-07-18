# $NetBSD: Makefile,v 1.1 2019/07/18 00:22:13 fox Exp $

DISTNAME=	exa-0.9.0
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

CARGO_CRATE_DEPENDS+=	aho-corasick-0.7.3
CARGO_CRATE_DEPENDS+=	ansi_term-0.12.0
CARGO_CRATE_DEPENDS+=	atty-0.2.11
CARGO_CRATE_DEPENDS+=	autocfg-0.1.4
CARGO_CRATE_DEPENDS+=	bitflags-1.0.4
CARGO_CRATE_DEPENDS+=	byteorder-1.3.2
CARGO_CRATE_DEPENDS+=	cc-1.0.35
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.7
CARGO_CRATE_DEPENDS+=	datetime-0.4.7
CARGO_CRATE_DEPENDS+=	env_logger-0.6.1
CARGO_CRATE_DEPENDS+=	git2-0.9.1
CARGO_CRATE_DEPENDS+=	glob-0.3.0
CARGO_CRATE_DEPENDS+=	humantime-1.2.0
CARGO_CRATE_DEPENDS+=	idna-0.1.5
CARGO_CRATE_DEPENDS+=	iso8601-0.1.1
CARGO_CRATE_DEPENDS+=	kernel32-sys-0.2.2
CARGO_CRATE_DEPENDS+=	lazy_static-1.3.0
CARGO_CRATE_DEPENDS+=	libc-0.2.51
CARGO_CRATE_DEPENDS+=	libgit2-sys-0.8.1
CARGO_CRATE_DEPENDS+=	libz-sys-1.0.25
CARGO_CRATE_DEPENDS+=	locale-0.2.2
CARGO_CRATE_DEPENDS+=	log-0.4.6
CARGO_CRATE_DEPENDS+=	matches-0.1.8
CARGO_CRATE_DEPENDS+=	memchr-2.2.0
CARGO_CRATE_DEPENDS+=	natord-1.0.9
CARGO_CRATE_DEPENDS+=	nom-1.2.4
CARGO_CRATE_DEPENDS+=	num-traits-0.1.43
CARGO_CRATE_DEPENDS+=	num-traits-0.2.6
CARGO_CRATE_DEPENDS+=	num_cpus-1.10.0
CARGO_CRATE_DEPENDS+=	number_prefix-0.3.0
CARGO_CRATE_DEPENDS+=	openssl-src-111.3.0+1.1.1c
CARGO_CRATE_DEPENDS+=	openssl-sys-0.9.47
CARGO_CRATE_DEPENDS+=	pad-0.1.5
CARGO_CRATE_DEPENDS+=	percent-encoding-1.0.1
CARGO_CRATE_DEPENDS+=	pkg-config-0.3.14
CARGO_CRATE_DEPENDS+=	quick-error-1.2.2
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.54
CARGO_CRATE_DEPENDS+=	redox_termios-0.1.1
CARGO_CRATE_DEPENDS+=	regex-1.1.6
CARGO_CRATE_DEPENDS+=	regex-syntax-0.6.6
CARGO_CRATE_DEPENDS+=	scoped_threadpool-0.1.9
CARGO_CRATE_DEPENDS+=	smallvec-0.6.9
CARGO_CRATE_DEPENDS+=	term_grid-0.1.7
CARGO_CRATE_DEPENDS+=	term_size-0.3.1
CARGO_CRATE_DEPENDS+=	termcolor-1.0.4
CARGO_CRATE_DEPENDS+=	termion-1.5.1
CARGO_CRATE_DEPENDS+=	thread_local-0.3.6
CARGO_CRATE_DEPENDS+=	ucd-util-0.1.3
CARGO_CRATE_DEPENDS+=	unicode-bidi-0.3.4
CARGO_CRATE_DEPENDS+=	unicode-normalization-0.1.8
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.5
CARGO_CRATE_DEPENDS+=	url-1.7.2
CARGO_CRATE_DEPENDS+=	users-0.9.1
CARGO_CRATE_DEPENDS+=	utf8-ranges-1.0.2
CARGO_CRATE_DEPENDS+=	vcpkg-0.2.6
CARGO_CRATE_DEPENDS+=	winapi-0.2.8
CARGO_CRATE_DEPENDS+=	winapi-0.3.7
CARGO_CRATE_DEPENDS+=	winapi-build-0.1.1
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-util-0.1.2
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	wincolor-1.0.1
CARGO_CRATE_DEPENDS+=	zoneinfo_compiled-0.4.8

INSTALLATION_DIRS=	bin \
			${PKGMANDIR}/man1 \
			share/bash-completion/completions \
			share/fish/vendor_completions.d \
			share/zsh/site-functions

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo build --locked --frozen --release

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/exa ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/contrib/man/exa.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/contrib/completions.bash \
			${DESTDIR}${PREFIX}/share/bash-completion/completions/exa
	${INSTALL_DATA} ${WRKSRC}/contrib/completions.fish \
			${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/exa.fish
	${INSTALL_DATA} ${WRKSRC}/contrib/completions.zsh \
			${DESTDIR}${PREFIX}/share/zsh/site-functions/_exa


.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
