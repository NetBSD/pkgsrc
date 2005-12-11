# $NetBSD: Makefile,v 1.18 2005/12/11 09:40:39 wiz Exp $
#

DISTNAME=	generator-0.35
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.squish.net/generator/
COMMENT=	Sega Mega drive genesis emulator

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
