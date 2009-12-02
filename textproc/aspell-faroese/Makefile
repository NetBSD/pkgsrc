# $NetBSD: Makefile,v 1.15 2009/12/02 17:56:26 snj Exp $

DISTNAME=	aspell-fo-0.2.38
PKGNAME=	${DISTNAME:C/-fo-/-faroese-/}
CATEGORIES=	textproc
MASTER_SITES=	http://fo.speling.org/filer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fo.speling.org/
COMMENT=	Faroese language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl
REPLACE_PERL=	unsq

INSTALLATION_DIRS=	lib/aspell share/aspell

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
