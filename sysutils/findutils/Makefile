# $NetBSD: Makefile,v 1.4 2002/02/18 15:14:41 seb Exp $
# FreeBSD Id: Makefile,v 1.13 1999/01/27 07:41:14 fenner Exp $

DISTNAME=	findutils-4.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=findutils/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/findutils/findutils.html
COMMENT=	The GNU find, xargs and locate utilities

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-prefix=g

INFO_FILES=		find.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
