# $NetBSD: Makefile,v 1.27 2025/01/24 09:26:11 riastradh Exp $

DISTNAME=	codebrowser-2.1.20231117
PKGNAME=	woboq_${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDAB/}
GITHUB_TAG=	1808e96d4c62417952389d536576d53bb6da4053

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codebrowser.dev/
COMMENT=	Code analysis tool
LICENSE=	cc-by-nc-sa-v3.0-license

# As of 2024-07:
#
# /pbulk/work/devel/woboq_codebrowser/work/codebrowser-1808e96d4c62417952389d536576d53bb6da4053/generator/inlayhintannotator.cpp: In member function 'std::string InlayHintsAnnotatorHelper::getParamNameInlayHint(clang::CallExpr*, clang::ParmVarDecl*, clang::Expr*)':
# /pbulk/work/devel/woboq_codebrowser/work/codebrowser-1808e96d4c62417952389d536576d53bb6da4053/generator/inlayhintannotator.cpp:273:52: error: 'class llvm::StringRef' has no member named 'startswith_insensitive'; did you mean 'starts_with_insensitive'?
#   273 |     if (f->getNumParams() == 1 && getSimpleName(f).startswith_insensitive("set"))
#       |                                                    ^~~~~~~~~~~~~~~~~~~~~~
#       |                                                    starts_with_insensitive
#
# As of 2024-12:
#
# /tmp/pkgbuild/2024Q4/devel/woboq_codebrowser/work/codebrowser-1808e96d4c62417952389d536576d53bb6da4053/generator/main.cpp: In function 'int main(int, const char**)':
# /tmp/pkgbuild/2024Q4/devel/woboq_codebrowser/work/codebrowser-1808e96d4c62417952389d536576d53bb6da4053/generator/main.cpp:461:24: error: 'class llvm::SmallString<128>' has no member named 'endswith'; did you mean 'ends_with'?
#          while (DirName.endswith("/"))
#                         ^~~~~~~~
#                         ends_with
BROKEN=		"Incompatible with llvm>=18"

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DLLVM_CONFIG_EXECUTABLE=${LLVM_CONFIG_PATH:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
#CMAKE_CONFIGURE_ARGS+=	-DCLANG_BUILTIN_HEADERS_DIR=${BUILDLINK_PREFIX.clang}/lib/clang/17/include
WRKSRC=		${WRKDIR}/codebrowser-${GITHUB_TAG}

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

.include "../../devel/cmake/build.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
