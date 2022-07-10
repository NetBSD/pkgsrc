# $NetBSD: Makefile,v 1.11 2022/07/10 02:55:02 khorben Exp $

.include "../../security/libpe/Makefile.common"

DISTNAME=	${GITHUB_PROJECT}-${PEV_VERSION}
GITHUB_PROJECT=	pev
GITHUB_TAG=	v${PKGVERSION_NOREV}

COMMENT=	The PE analysis toolkit
LICENSE=	gnu-gpl-v3

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

.include "../../security/libpe/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
