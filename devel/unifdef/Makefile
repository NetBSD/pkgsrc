# $NetBSD: Makefile,v 1.1 2021/07/23 11:16:03 wiz Exp $

DISTNAME=	unifdef-2.12
CATEGORIES=	devel
MASTER_SITES=	http://dotat.at/prog/unifdef/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dotat.at/prog/unifdef/
COMMENT=	Selectively remove C preprocessor conditionals
LICENSE=	2-clause-bsd AND modified-bsd

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
