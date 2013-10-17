# $NetBSD: Makefile,v 1.25 2013/10/17 15:32:22 roy Exp $

DISTNAME=	aalib-1.4rc5
PKGNAME=	${DISTNAME:S/rc5/.0.5/}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aa-project/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aa-project.sourceforge.net/aalib/
COMMENT=	ASCII Art library
LICENSE=	gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/aalib-1.4.0
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes

CONFIGURE_ENV+=		SLANG_PREFIX=${BUILDLINK_PREFIX.libslang:Q}
CONFIGURE_ENV+=		NCURSES_PREFIX=${BUILDLINK_PREFIX.curses:Q}

SUBST_CLASSES+=		malloc
SUBST_STAGE.malloc=	pre-configure
SUBST_FILES.malloc=	src/aalinux.c src/aax.c src/aaxkbd.c		\
			src/aaxmouse.c src/aarec.c src/aalib.c		\
			src/aaedit.c src/aaregist.c src/aakbdreg.c	\
			src/aamoureg.c src/aados.c src/aadoskbd.c
SUBST_SED.malloc=	-e 's|<malloc.h>|<stdlib.h>|g'

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
