# $NetBSD: Makefile,v 1.6 2021/09/11 05:48:30 mef Exp $

DISTNAME=	aha-0.5.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=theZiz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/theZiz/aha/
COMMENT=	Ansi HTML Adapter
# It's not specified what version of LGPL
LICENSE=	mpl-1.1 OR gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	MANMODE=${MANMODE}
MAKE_ENV+=	BINMODE=${BINMODE}

.include "../../mk/bsd.pkg.mk"
