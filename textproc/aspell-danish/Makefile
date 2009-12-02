# $NetBSD: Makefile,v 1.15 2009/12/02 17:51:25 snj Exp $

DISTNAME=	aspell-da-1.7.30
PKGNAME=	${DISTNAME:C/-da-/-danish-/}
CATEGORIES=	textproc
MASTER_SITES=	http://da.speling.org/filer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://da.speling.org/
COMMENT=	Danish language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl
REPLACE_PERL=	unsq

INSTALLATION_DIRS=	lib/aspell share/aspell

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
