# $NetBSD: Makefile,v 1.8 2004/05/03 15:58:55 wiz Exp $

DISTNAME=	guile-www-1.0.1
PKGREVISION=	2
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	epg@pretzelnet.org
HOMEPAGE=	http://www.gnu.org/software/guile/
COMMENT=	Guile WWW module

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
INFO_FILES=	guile-www.info

.include "../../lang/guile14/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
