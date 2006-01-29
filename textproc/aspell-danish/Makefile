# $NetBSD: Makefile,v 1.11 2006/01/29 01:42:27 wiz Exp $
#

DISTNAME=	aspell-da-1.4.52
PKGNAME=	${DISTNAME:C/-da-/-danish-/}
CATEGORIES=	textproc
MASTER_SITES=	http://da.speling.org/filer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://da.speling.org/
COMMENT=	Danish language support for aspell

USE_TOOLS+=	perl
REPLACE_PERL=	unsq

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
