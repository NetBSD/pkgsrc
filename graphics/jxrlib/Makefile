# $NetBSD: Makefile,v 1.5 2026/10/30 10:32:52 prlw1 Exp $

DISTNAME=	jxrlib-1.4.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mircomir/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mircomir/jxrlib
COMMENT=	JPEG XR library
LICENSE=	2-clause-bsd

USE_TOOLS=	gmake
TOOL_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
MAKE_ENV+=	BIG_ENDIAN="true"
ENDIANFLAG=	-D_BIG__ENDIAN_
.else
ENDIANFLAG=
.endif
MAKE_ENV+=	DIR_INSTALL=${DESTDIR}${PREFIX}
MAKE_ENV+=	SHARED="true"

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib

PKGCONFIG_OVERRIDE+=	libjxr.pc.in
SUBST_CLASSES+=		avoidpy
SUBST_FILES.avoidpy=	libjxr.pc.in
SUBST_STAGE.avoidpy=	pre-build
SUBST_MESSAGE.avoidpy=	Substitute variables in .pc.in file
SUBST_SED.avoidpy=	-e 's,%(DIR_INSTALL)s,${PREFIX},g'
SUBST_SED.avoidpy+=	-e 's,%(JXR_VERSION)s,${PKGVERSION_NOREV},g'
SUBST_SED.avoidpy+=	-e 's,%(JXR_ENDIAN)s,${ENDIANFLAG},g'

pre-patch:
	dos2unix ${WRKSRC}/Makefile
	find ${WRKSRC} -name '*.c' -print0 | xargs -0 dos2unix
	find ${WRKSRC} -name '*.h' -print0 | xargs -0 dos2unix

.include "../../mk/bsd.pkg.mk"
