# $NetBSD: Makefile,v 1.23 2004/10/03 00:12:57 tv Exp $

DISTNAME=		pari-2.1.5
PKGREVISION=		4
CATEGORIES=		math
MASTER_SITES=		http://pari.math.u-bordeaux.fr/download/ \
			ftp://www.gn-50uma.de/gn/gn-50uma.de/pari-2.1/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pari.math.u-bordeaux.fr/
COMMENT=		Software package for computer-aided number theory

BUILD_DEPENDS+= 	teTeX-[0-9]*:../../print/teTeX

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_X11=		yes
USE_GNU_READLINE=	# rl_save_prompt

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/Configure
CONFIGURE_ARGS+=	--prefix=${PREFIX} --share-prefix=${PREFIX}/share
CONFIGURE_ARGS+=	--graphic=X11
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=		X11BASE=${X11BASE}

TEST_TARGET=		test-compat bench

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
