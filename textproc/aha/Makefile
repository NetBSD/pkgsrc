# $NetBSD: Makefile,v 1.3 2016/07/14 13:18:08 mef Exp $

DISTNAME=	aha-0.4.9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=theZiz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/theZiz/aha/
COMMENT=	Ansi HTML Adapter
# It's not specified what version of LGPL
LICENSE=	mpl-1.1 OR gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3

MAKE_ENV+=	MANDIR=${PKGMANDIR}
MAKE_ENV+=	MANMODE=${MANMODE}
MAKE_ENV+=	BINMODE=${BINMODE}

.include "../../mk/bsd.pkg.mk"
