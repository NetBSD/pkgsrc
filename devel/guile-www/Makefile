# $NetBSD: Makefile,v 1.4 2003/06/05 05:01:56 uebayasi Exp $

DISTNAME=	guile-www-1.0.1
PKGREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	epg@pretzelnet.org
HOMEPAGE=	http://www.gnu.org/software/guile/
COMMENT=	Guile WWW module

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
