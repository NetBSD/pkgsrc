# $NetBSD: Makefile,v 1.2 2007/02/19 18:20:48 joerg Exp $

DISTNAME=	lush-1.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lush/}

MAINTAINER=	dauphin@enst.fr
HOMEPAGE=	http://lush.sourceforge.net/
COMMENT=	Lisp interpreter/compiler with a seamless interface to C

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--without-bfd

post-install:
	${RM} ${PREFIX}/share/lush/src/*c.orig

.include "../../math/gsl/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
