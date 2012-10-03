# $NetBSD: Makefile,v 1.24 2012/10/03 12:55:12 asau Exp $
#

DISTNAME=	generator-0.35
PKGREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.squish.net/generator/
COMMENT=	Sega Mega drive genesis emulator

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes

.if (${MACHINE_ARCH} == "i386")
BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm
CONFIGURE_ARGS+=	--with-gtk --with-raze
.else
CONFIGURE_ARGS+=	--with-gtk --with-cmz80
.endif

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DBYTES_HIGHFIRST
.endif

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
