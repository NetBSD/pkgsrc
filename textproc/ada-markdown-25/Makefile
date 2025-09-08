# $NetBSD: Makefile,v 1.2 2025/09/08 16:37:37 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-25.0.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	markdown
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/markdown
COMMENT=	Markdown parser written in Ada
LICENSE=	apache-2.0

USE_TOOLS+=	gmake

USE_LANGUAGES=	ada

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=			yes
MAKE_FLAGS+=			ALL_LIBRARY_TYPES='static static-pic relocatable'
BUILDLINK_DEPMETHOD.xmlada=	full
BUILDLINK_DEPMETHOD.vss-25=	full
.else
MAKE_FLAGS+=			ALL_LIBRARY_TYPES=static
.endif

MAKE_FLAGS+=			PREFIX=${GNAT_PREFIX} BUILD_MODE=prod

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../textproc/ada-vss-25/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
