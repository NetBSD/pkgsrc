# $NetBSD: Makefile,v 1.12 2006/02/05 23:10:59 joerg Exp $
#

DISTNAME=	aspell-fo-0.2.24
PKGNAME=	${DISTNAME:C/-fo-/-faroese-/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://fo.speling.org/filer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fo.speling.org/
COMMENT=	Faroese language support for aspell

USE_TOOLS+=	perl
REPLACE_PERL=	unsq

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
