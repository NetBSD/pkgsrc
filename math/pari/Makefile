# $NetBSD: Makefile,v 1.27 2005/07/16 19:10:39 jlam Exp $

DISTNAME=		pari-2.1.5
PKGREVISION=		5
CATEGORIES=		math
MASTER_SITES=		http://pari.math.u-bordeaux.fr/download/ \
			ftp://www.gn-50uma.de/gn/gn-50uma.de/pari-2.1/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pari.math.u-bordeaux.fr/
COMMENT=		Software package for computer-aided number theory

BUILD_DEPENDS+= 	teTeX-[0-9]*:../../print/teTeX

USE_LIBTOOL=		yes
USE_GNU_READLINE=	# rl_save_prompt
USE_TOOLS+=		perl:run

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/Configure
CONFIGURE_ARGS+=	--prefix=${PREFIX} --share-prefix=${PREFIX}/share
CONFIGURE_ARGS+=	--graphic=X11
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=		PERL5=${PERL5}
CONFIGURE_ENV+=		X11BASE=${X11BASE}

TEST_TARGET=		test-compat bench

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
