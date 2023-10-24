# $NetBSD: Makefile,v 1.10 2023/10/24 22:09:01 wiz Exp $

GITHUB_PROJECT=	helix
DISTNAME=	22.12
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=helix-editor/}
DIST_SUBDIR=	${GITHUB_PROJECT}

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
.for name rev url path in ${TS_FILES}
	${LN} -s ${WRKDIR}/${name}-${rev} ${WRKSRC}/runtime/grammars/sources/${path}
.endfor

SUBST_CLASSES+=		datadir
SUBST_STAGE.datadir=	pre-configure
SUBST_MESSAGE.datadir=	Fixing datadir
SUBST_FILES.datadir=	helix-loader/src/lib.rs
SUBST_SED.datadir+=	-e 's,%%DATADIR%%,${PREFIX}/share/helix,g'

.include "../../mk/bsd.prefs.mk"

post-build:
	${RUN} cd ${WRKSRC} && env HELIX_RUNTIME=${WRKSRC}/runtime \
		./target/release/hx --grammar build
.if ${OPSYS} == "Darwin"
	${RUN} cd ${WRKSRC}/runtime/grammars &&				\
	for f in *.so; do						\
		install_name_tool					\
		    -id ${PREFIX}/share/helix/runtime/grammars/$${f}	\
		    $${f};						\
	done
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/hx ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/runtime && ${PAX} -rw themes ${DESTDIR}${PREFIX}/share/helix/runtime/
	cd ${WRKSRC}/runtime && ${PAX} -rw queries ${DESTDIR}${PREFIX}/share/helix/runtime/
	cd ${WRKSRC}/contrib && ${PAX} -rw completion ${DESTDIR}${PREFIX}/share/examples/helix/
	${INSTALL_DATA} ${WRKSRC}/runtime/tutor ${DESTDIR}${PREFIX}/share/helix/runtime/tutor
	${INSTALL_LIB} ${WRKSRC}/runtime/grammars/*.so ${DESTDIR}${PREFIX}/share/helix/runtime/grammars/

.PHONY: print-tree-sitter-depends
print-tree-sitter-depends:
	${RUN}${AWK} -f ${FILESDIR}/print-depends.awk ${WRKSRC}/languages.toml

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
