# $NetBSD: Makefile,v 1.12 2006/02/05 23:10:59 joerg Exp $
#

DISTNAME=	aspell-da-1.4.52
PKGNAME=	${DISTNAME:C/-da-/-danish-/}
PKGREVISION=	1
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
