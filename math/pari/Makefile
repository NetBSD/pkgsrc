# $NetBSD: Makefile,v 1.41 2009/02/25 03:33:03 minskim Exp $

DISTNAME=	pari-2.1.6
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/unix/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pari.math.u-bordeaux.fr/
COMMENT=	Software package for computer-aided number theory

BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk

PKG_DESTDIR_SUPPORT=	user-destdir

TEX_ACCEPTED=	teTeX3
TEX_DEPMETHOD=	build

USE_GNU_READLINE=	yes	# rl_save_prompt()
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/Configure
CONFIGURE_ARGS+=	--graphic=X11
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}/man1
CONFIGURE_ARGS+=	--share-prefix=${PREFIX}/share
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE:Q}
CONFIGURE_ENV+=		PERL5=${PERL5:Q}
CONFIGURE_ENV+=		X11BASE=${X11BASE:Q}
CONFIGURE_ENV+=		Xincroot=${X11BASE}/include

TEST_TARGET=		test-compat bench

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
