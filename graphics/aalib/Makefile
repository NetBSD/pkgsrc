# $NetBSD: Makefile,v 1.20 2006/10/09 12:52:35 joerg Exp $

DISTNAME=	aalib-1.4rc5
PKGNAME=	${DISTNAME:S/rc5/.0.5/}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aa-project/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://aa-project.sourceforge.net/aalib/
COMMENT=	ASCII Art library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/aalib-1.4.0
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
INFO_FILES=		# PLIST

CONFIGURE_ENV+=		SLANG_PREFIX=${BUILDLINK_PREFIX.libslang:Q}
CONFIGURE_ENV+=		NCURSES_PREFIX=${BUILDLINK_PREFIX.ncurses:Q}

SUBST_CLASSES+=		malloc
SUBST_STAGE.malloc=	pre-configure
SUBST_FILES.malloc=	src/aalinux.c src/aax.c src/aaxkbd.c		\
			src/aaxmouse.c src/aarec.c src/aalib.c		\
			src/aaedit.c src/aaregist.c src/aakbdreg.c	\
			src/aamoureg.c src/aados.c src/aadoskbd.c
SUBST_SED.malloc=	-e 's|<malloc.h>|<stdlib.h>|g'

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
