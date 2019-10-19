# $NetBSD: Makefile,v 1.1 2019/10/19 13:38:43 nia Exp $

DISTNAME=	aspell6-fa-0.11-0
PKGNAME=	${DISTNAME:S/^aspell6/aspell/1:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/fa/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Persian language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
