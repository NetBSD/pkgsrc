# $NetBSD: Makefile,v 1.55 2026/06/16 12:12:14 nia Exp $

DISTNAME=	plotutils-2.6
PKGREVISION=	4
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/plotutils/plotutils.html
COMMENT=	Programs and library for plotting scientific data
LICENSE=	gnu-gpl-v3

CONFLICTS+=	plotutils-nox11-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		lex:run yacc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libplotter
MAKE_JOBS_SAFE=		no
INFO_FILES=		yes

# This defines its own bool type, which is incompatible
# with C23 having it as a built-in keyword.
#
# gnu99 is chosen for being the minimum bootstrap requirement
# and safety against APIs being hidden in standards mode.
FORCE_C_STD=		gnu99

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
