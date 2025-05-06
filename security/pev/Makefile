# $NetBSD: Makefile,v 1.13 2025/05/06 12:07:36 wiz Exp $

PKGREVISION= 1
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

.include "../../security/libpe/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
