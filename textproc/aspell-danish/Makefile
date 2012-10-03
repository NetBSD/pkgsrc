# $NetBSD: Makefile,v 1.17 2012/10/03 21:57:46 wiz Exp $

DISTNAME=	aspell-da-1.7.30
PKGNAME=	${DISTNAME:C/-da-/-danish-/}
PKGREVISION=	2
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
