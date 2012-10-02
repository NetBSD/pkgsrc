# $NetBSD: Makefile,v 1.9 2012/10/02 20:11:45 asau Exp $

DISTNAME=	lush-1.2.1
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lush/}

MAINTAINER=	dauphin@enst.fr
HOMEPAGE=	http://lush.sourceforge.net/
COMMENT=	Lisp interpreter/compiler with a seamless interface to C

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_GNU_READLINE=	yes # rl_getc, rl_basic_quote_characters, rl_insert_close

CONFIGURE_ARGS+=	--without-bfd

WRKSRC=		${WRKDIR}/lush

post-install:
	${RM} ${DESTDIR}${PREFIX}/share/lush/lsh/libc/*.lsh.orig

.include "../../math/gsl/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
