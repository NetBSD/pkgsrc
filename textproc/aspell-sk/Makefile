# $NetBSD: Makefile,v 1.1 2013/04/09 02:33:48 rodent Exp $
#

DISTNAME=	aspell-sk-0.52-0
PKGNAME=	${DISTNAME:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	http://sk-spell.sk.cx/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://sk-spell.sk.cx/
COMMENT=	Slovak language support for aspell

HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
