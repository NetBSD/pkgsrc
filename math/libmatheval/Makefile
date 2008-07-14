# $NetBSD: Makefile,v 1.10 2008/07/14 12:56:08 joerg Exp $
#

DISTNAME=		libmatheval-1.1.4
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GNU:=libmatheval/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/libmatheval/
COMMENT=		Library for evaluating mathematical expressions

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		require
INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	libmatheval.pc.in

.include "../../devel/flex/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
