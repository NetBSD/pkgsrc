# $NetBSD: Makefile,v 1.2 2000/02/05 17:29:06 wiz Exp $
# FreeBSD Id: Makefile,v 1.13 1999/01/27 07:41:14 fenner Exp $

DISTNAME=	findutils-4.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=findutils/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/findutils/findutils.html

USE_GTEXINFO=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-prefix=g

INFO_FILES=		find.info

.include "../../mk/bsd.pkg.mk"
