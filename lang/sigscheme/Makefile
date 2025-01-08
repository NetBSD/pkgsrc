# $NetBSD: Makefile,v 1.11 2025/01/08 02:36:37 ktnb Exp $

DISTNAME=	sigscheme-0.9.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=uim/}
GITHUB_PROJECT=	sigscheme
GITHUB_RELEASE=	0.9.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/uim/sigscheme
COMMENT=	R5RS Scheme interpreter for embedded use
#LICENSE=	# See ${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gmake pkg-config perl:run

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	ruby-[0-9]*:../../lang/ruby

PKGCONFIG_OVERRIDE+=	libgcroots/gcroots.pc.in
PKGCONFIG_OVERRIDE+=	sigscheme.pc.in

CONFIGURE_ARGS+=	--enable-conf=full
CONFIGURE_ARGS+=	--with-libgcroots=installed
CONFIGURE_ARGS+=	--enable-maintainer-mode

TEST_TARGET=	check

CFLAGS+=		-std=c99

REPLACE_RUBY+=	tools/build_func_table.rb
REPLACE_RUBY+=	tools/scm_decl.rb
REPLACE_RUBY+=	tools/check_declare_func_typo.rb
REPLACE_RUBY+=	tools/summarize_quality.rb
REPLACE_RUBY+=	tools/check_initialize_scm_null.rb

.include "../../lang/ruby/replace.mk"

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/libgcroots/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
