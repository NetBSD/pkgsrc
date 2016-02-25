# $NetBSD: Makefile,v 1.35 2016/02/25 12:12:50 jperkin Exp $

DISTNAME=	yasm-1.3.0
CATEGORIES=	devel
MASTER_SITES=	http://www.tortall.net/projects/yasm/releases/

MAINTAINER=	shaun@inerd.com
HOMEPAGE=	http://www.tortall.net/projects/yasm/
COMMENT=	Complete rewrite of the NASM assembler with BSD license
LICENSE=	modified-bsd AND (artistic OR gnu-gpl-v2 OR gnu-lgpl-v2)

USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

# Commit message suggests this is Darwin-specific.  Won't work to
# cross-compile to Darwin, but that doesn't work at all anyway.
SUBST_CLASSES.Darwin+=	link
SUBST_STAGE.link=	pre-configure
SUBST_MESSAGE.link=	Fix linking command.
SUBST_FILES.link=	Makefile.in
SUBST_SED.link=		-e 's,$$(CCLD_FOR_BUILD) -o $$@,$$(LINK) -o $$@,'

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
CONFIGURE_ENV+=		CCLD_FOR_BUILD=${NATIVE_CC:Q}
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
