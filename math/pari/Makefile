# $NetBSD: Makefile,v 1.45 2010/02/19 08:33:28 schmonz Exp $

DISTNAME=	pari-2.3.5
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/unix/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pari.math.u-bordeaux.fr/
COMMENT=	Software package for computer-aided number theory
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no

BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk

PKG_DESTDIR_SUPPORT=	user-destdir

TEX_ACCEPTED=	teTeX3
TEX_DEPMETHOD=	build

USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run imake
USE_LANGUAGES+=		c c++
USE_GNU_READLINE=	yes	# rl_save_prompt()
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE:Q}
CONFIGURE_ENV+=		PERL5=${PERL5:Q}

CONFIGURE_SCRIPT=	${WRKSRC}/Configure
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}/man1
CONFIGURE_ARGS+=	--share-prefix=${PREFIX}/share

REPLACE_PERL+=		src/desc/PARI/822.pm

TEST_TARGET=		test-compat bench

.include "options.mk"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
