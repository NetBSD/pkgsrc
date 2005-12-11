# $NetBSD: Makefile,v 1.16 2005/12/11 09:40:44 wiz Exp $

DISTNAME=	aalib-1.4rc5
PKGNAME=	${DISTNAME:S/rc5/.0.5/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aa-project/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://aa-project.sourceforge.net/aalib/
COMMENT=	ASCII Art library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/aalib-1.4.0
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

SUBST_CLASSES+=		malloc paths

SUBST_STAGE.malloc=	pre-configure
SUBST_FILES.malloc=	src/aalinux.c src/aax.c src/aaxkbd.c
SUBST_FILES.malloc+=	src/aaxmouse.c src/aarec.c src/aalib.c
SUBST_FILES.malloc+=	src/aaedit.c src/aaregist.c src/aakbdreg.c
SUBST_FILES.malloc+=	src/aamoureg.c src/aados.c src/aadoskbd.c
SUBST_SED.malloc=	-e 's|<malloc.h>|<stdlib.h>|g'

SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	configure
SUBST_SED.paths=	-e 's|BUILDLINK_SL|${BUILDLINK_PREFIX.libslang}|g'
SUBST_SED.paths+=	-e 's|BUILDLINK_NC|${BUILDLINK_PREFIX.ncurses}|g'

INFO_FILES=	aalib.info

.include "options.mk"

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

.include "../../mk/bsd.pkg.mk"
