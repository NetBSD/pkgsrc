# $NetBSD: Makefile,v 1.7 2003/08/09 10:44:43 seb Exp $

DISTNAME=	guile-www-1.0.1
PKGREVISION=	2
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	epg@pretzelnet.org
HOMEPAGE=	http://www.gnu.org/software/guile/
COMMENT=	Guile WWW module

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
INFO_FILES=	guile-www.info

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
