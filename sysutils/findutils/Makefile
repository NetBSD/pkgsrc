# $NetBSD: Makefile,v 1.5 2002/10/22 11:35:39 wiz Exp $
#

DISTNAME=	findutils-4.1
PKGREVISION=	1
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
