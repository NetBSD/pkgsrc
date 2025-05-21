# $NetBSD: Makefile,v 1.24 2025/05/21 18:30:34 schmonz Exp $

DISTNAME=		astyle-3.6.9
CATEGORIES=		devel textproc
MASTER_SITES=		http://www.andre-simon.de/zip/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://astyle.sourceforge.net/
COMMENT=		Automatic formatter for C, C++, C++/CLI, C\#, and Java
LICENSE=		gnu-lgpl-v3

USE_TOOLS+=		gmake
USE_LANGUAGES=		c++
AUTO_MKDIRS=		yes

CMAKE_CONFIGURE_ARGS+=	-DBUILD_JAVA_LIBS=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_STATIC_LIBS=OFF
CMAKE_CONFIGURE_ARGS+=	-DINSTALL_DOC=ON

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	CMakeLists.txt
SUBST_VARS.paths=	PKGMANDIR

post-install:
	${INSTALL_DATA} ${WRKSRC}/sh-completion/astyle.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/astyle
	${INSTALL_DATA} ${WRKSRC}/sh-completion/astyle.fish \
		${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/
	${INSTALL_DATA} ${WRKSRC}/sh-completion/astyle.zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_astyle

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
