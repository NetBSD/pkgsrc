# $NetBSD: Makefile,v 1.48 2010/03/24 19:43:27 asau Exp $

DISTNAME=	pari-2.3.5
PKGREVISION=	5
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pari.math.u-bordeaux.fr/
COMMENT=	Software package for computer-aided number theory
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
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

BUILD_TARGET=		all
TEST_TARGET=		test-compat bench
INSTALL_TARGET=		install

.include "options.mk"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
