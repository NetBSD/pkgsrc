# $NetBSD: Makefile,v 1.1 2013/04/09 02:33:40 rodent Exp $
#

DISTNAME=	aspell6-en-6.0-0
PKGNAME=	${DISTNAME:S/6-/-/1:S/-0/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/en/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	English language support for aspell

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	ASPELL=${BUILDLINK_PREFIX.aspell}/bin/aspell
CONFIGURE_ENV+=	PREZIP=${BUILDLINK_PREFIX.aspell}/bin/prezip-bin

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
