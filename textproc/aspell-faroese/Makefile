# $NetBSD: Makefile,v 1.11 2006/01/29 01:59:02 wiz Exp $
#

DISTNAME=	aspell-fo-0.2.24
PKGNAME=	${DISTNAME:C/-fo-/-faroese-/}
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
