# $NetBSD: Makefile,v 1.1 2022/01/13 14:13:59 schmonz Exp $

DISTNAME=	hexyl-0.9.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sharkdp/hexyl/
COMMENT=	Command-line hex viewer
LICENSE=	apache-2.0

CARGO_CRATE_DEPENDS+=	aho-corasick-0.7.18
CARGO_CRATE_DEPENDS+=	ansi_term-0.11.0
CARGO_CRATE_DEPENDS+=	ansi_term-0.12.1
CARGO_CRATE_DEPENDS+=	anyhow-1.0.42
CARGO_CRATE_DEPENDS+=	assert_cmd-1.0.7
CARGO_CRATE_DEPENDS+=	atty-0.2.14
CARGO_CRATE_DEPENDS+=	autocfg-1.0.1
CARGO_CRATE_DEPENDS+=	bitflags-1.2.1
CARGO_CRATE_DEPENDS+=	bstr-0.2.16
CARGO_CRATE_DEPENDS+=	clap-2.33.3
CARGO_CRATE_DEPENDS+=	difflib-0.4.0
CARGO_CRATE_DEPENDS+=	doc-comment-0.3.3
CARGO_CRATE_DEPENDS+=	either-1.6.1
CARGO_CRATE_DEPENDS+=	float-cmp-0.8.0
CARGO_CRATE_DEPENDS+=	hermit-abi-0.1.19
CARGO_CRATE_DEPENDS+=	itertools-0.10.1
CARGO_CRATE_DEPENDS+=	lazy_static-1.4.0
CARGO_CRATE_DEPENDS+=	libc-0.2.98
CARGO_CRATE_DEPENDS+=	memchr-2.4.0
CARGO_CRATE_DEPENDS+=	normalize-line-endings-0.3.0
CARGO_CRATE_DEPENDS+=	num-traits-0.2.14
CARGO_CRATE_DEPENDS+=	predicates-2.0.0
CARGO_CRATE_DEPENDS+=	predicates-core-1.0.2
CARGO_CRATE_DEPENDS+=	predicates-tree-1.0.2
CARGO_CRATE_DEPENDS+=	proc-macro2-1.0.27
CARGO_CRATE_DEPENDS+=	quote-1.0.9
CARGO_CRATE_DEPENDS+=	regex-1.5.4
CARGO_CRATE_DEPENDS+=	regex-automata-0.1.10
CARGO_CRATE_DEPENDS+=	regex-syntax-0.6.25
CARGO_CRATE_DEPENDS+=	strsim-0.8.0
CARGO_CRATE_DEPENDS+=	syn-1.0.73
CARGO_CRATE_DEPENDS+=	term_size-0.3.2
CARGO_CRATE_DEPENDS+=	textwrap-0.11.0
CARGO_CRATE_DEPENDS+=	thiserror-1.0.26
CARGO_CRATE_DEPENDS+=	thiserror-impl-1.0.26
CARGO_CRATE_DEPENDS+=	treeline-0.1.0
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.8
CARGO_CRATE_DEPENDS+=	unicode-xid-0.2.2
CARGO_CRATE_DEPENDS+=	wait-timeout-0.2.0
CARGO_CRATE_DEPENDS+=	winapi-0.3.9
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0

USE_LANGUAGES=		c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/${PKGBASE} ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
