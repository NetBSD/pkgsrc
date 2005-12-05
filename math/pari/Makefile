# $NetBSD: Makefile,v 1.31 2005/12/05 20:50:37 rillig Exp $

DISTNAME=	pari-2.1.6
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/unix/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pari.math.u-bordeaux.fr/
COMMENT=	Software package for computer-aided number theory

TEX_ACCEPTED=	teTeX1 teTeX2 teTeX3
TEX_DEPMETHOD=	build

USE_GNU_READLINE=	yes	# rl_save_prompt()
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/Configure
CONFIGURE_ARGS+=	--graphic=X11
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--share-prefix=${PREFIX}/share
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE:Q}
CONFIGURE_ENV+=		PERL5=${PERL5:Q}
CONFIGURE_ENV+=		X11BASE=${X11BASE:Q}

TEST_TARGET=		test-compat bench

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
