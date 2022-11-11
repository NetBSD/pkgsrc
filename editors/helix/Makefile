# $NetBSD: Makefile,v 1.7 2022/11/11 20:23:39 nikita Exp $

GITHUB_PROJECT=	helix
DISTNAME=	22.08.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=helix-editor/}
DIST_SUBDIR=	${GITHUB_PROJECT}

DISTFILES+=	${DISTNAME}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://helix-editor.com/
COMMENT=	Modal editor inspired by kakoune / neovim
# Additionally, the tree-sitter sources have various licenses.
LICENSE=	mpl-2.0
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	share/helix/runtime/grammars
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/examples/helix/completion

.include "cargo-depends.mk"
.include "tree-sitter-depends.mk"

post-extract:
	${MKDIR} ${WRKSRC}/runtime/grammars/sources
.for dir in ${TREESITTER_DISTFILES}
	${MV} ${WRKDIR}/${dir:S/.tar.gz//} ${WRKSRC}/runtime/grammars/sources/${dir:S/tree-sitter-//:C/-[^-]*$//}
.endfor
	(cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a typescript tsx)
	(cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a ocaml ocaml-interface)
	(cd ${WRKSRC}/runtime/grammars/sources && ${CP} -a markdown markdown_inline)
	(cd ${WRKSRC}/runtime/grammars/sources && ${MV} diff git-diff)

SUBST_CLASSES+=		datadir
SUBST_STAGE.datadir=	post-patch
SUBST_MESSAGE.datadir=	Fixing datadir
SUBST_FILES.datadir=	helix-loader/src/lib.rs
SUBST_SED.datadir+=	-e 's,%%DATADIR%%,${PREFIX}/share/helix,g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/hx ${DESTDIR}${PREFIX}/bin

post-install:
	cd ${WRKSRC}/runtime && ${PAX} -rw themes ${DESTDIR}${PREFIX}/share/helix/runtime/
	cd ${WRKSRC}/runtime && ${PAX} -rw queries ${DESTDIR}${PREFIX}/share/helix/runtime/
	cd ${WRKSRC}/contrib && ${PAX} -rw completion ${DESTDIR}${PREFIX}/share/examples/helix/
	${INSTALL_DATA} ${WRKSRC}/runtime/tutor.txt ${DESTDIR}${PREFIX}/share/helix/runtime/tutor.txt
	${INSTALL_LIB} ${WRKSRC}/runtime/grammars/*.so ${DESTDIR}${PREFIX}/share/helix/runtime/grammars/

.include "../../editors/helix/languages2mk.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
