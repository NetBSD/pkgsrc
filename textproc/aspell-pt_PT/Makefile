# $NetBSD: Makefile,v 1.3 2019/10/19 11:01:25 nia Exp $

DISTNAME=	aspell6-pt_PT-20190329-1-0
PKGNAME=	${DISTNAME:S/6-/-/1:S/-1/.1/1:S/-0/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/pt_PT/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Portuguese language support for aspell
LICENSE=	gnu-gpl-v3

CONFLICTS+=	aspell-portuguese-[0-9]*
HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
