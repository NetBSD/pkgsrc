# $NetBSD: Makefile,v 1.5 2003/06/23 11:12:16 seb Exp $

DISTNAME=	guile-www-1.0.1
PKGREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	epg@pretzelnet.org
HOMEPAGE=	http://www.gnu.org/software/guile/
COMMENT=	Guile WWW module

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_NEW_TEXINFO=	YES
INFO_FILES=	guile-www.info

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
