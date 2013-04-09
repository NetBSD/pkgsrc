# $NetBSD: Makefile,v 1.1 2013/04/09 02:33:50 rodent Exp $

DISTNAME=	aspell6-uk-1.4.0-0
PKGNAME=	${DISTNAME:S/6-/-/1:S/-0/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/uk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Ukrainian language support for aspell

HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
