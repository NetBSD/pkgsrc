# $NetBSD: Makefile,v 1.4 2004/11/13 13:18:07 kristerw Exp $
#

DISTNAME=		libmatheval-1.1.1
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GNU:=libmatheval/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/libmatheval/
COMMENT=		Library for evaluating mathematical expressions

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		require

.include "../../devel/flex/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
