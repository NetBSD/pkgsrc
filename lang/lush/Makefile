# $NetBSD: Makefile,v 1.13 2020/03/20 11:57:55 nia Exp $

DISTNAME=	lush-1.2.1
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lush/}

MAINTAINER=	dauphin@enst.fr
HOMEPAGE=	http://lush.sourceforge.net/
COMMENT=	Lisp interpreter/compiler with a seamless interface to C

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--without-bfd

WRKSRC=		${WRKDIR}/lush

post-install:
	${RM} ${DESTDIR}${PREFIX}/share/lush/lsh/libc/*.lsh.orig

.include "../../math/gsl/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
# rl_getc, rl_basic_quote_characters, rl_insert_close
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
