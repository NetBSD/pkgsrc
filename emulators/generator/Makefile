# $NetBSD: Makefile,v 1.12 2004/10/03 00:14:40 tv Exp $
#

DISTNAME=	generator-0.34
PKGREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sqish.net/generator/
COMMENT=	Sega Mega drive genesis emulator

USE_BUILDLINK3=		yes
USE_X11=		# defined
GNU_CONFIGURE=		# defined

.if (${MACHINE_ARCH} == "i386")
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
