# $NetBSD: Makefile,v 1.3 2003/01/07 11:42:31 uebayasi Exp $

DISTNAME=	guile-www-1.0.1
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
