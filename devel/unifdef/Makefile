# $NetBSD: Makefile,v 1.3 2026/06/14 18:33:50 nia Exp $

DISTNAME=	unifdef-2.12
CATEGORIES=	devel
MASTER_SITES=	https://dotat.at/prog/unifdef/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dotat.at/prog/unifdef/
COMMENT=	Selectively remove C preprocessor conditionals
LICENSE=	2-clause-bsd AND modified-bsd

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

# Uses constexpr as a variable name, which conflicts with the
# C23 keyword.
FORCE_C_STD=	gnu99

.include "../../mk/bsd.pkg.mk"
