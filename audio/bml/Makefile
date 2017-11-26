# $NetBSD: Makefile,v 1.11 2017/11/26 10:38:20 wiz Exp $

DISTNAME=	bml-0.8.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buzztard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://buzztrax.org/
COMMENT=	Buzz machine loader
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99 c++

PKGCONFIG_OVERRIDE+=	libbml.pc.in

CFLAGS+=	-DHAVE_VSSCANF=1	# missing configure logic

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
LDFLAGS+=	-li386			# for i386_set_ldt
.endif

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
