# $NetBSD: Makefile,v 1.28 2026/01/02 12:29:21 adam Exp $

DISTNAME=	libvisual-0.4.2
CATEGORIES=	audio graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Libvisual/}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Libvisual/libvisual
COMMENT=	Abstraction library for applications and audio visualisation plugins
LICENSE=	gnu-lgpl-v2.1

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libvisual.pc.in

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
RT_LIB_SCHED=		-lrt
.else
RT_LIB_SCHED=		# empty
.endif
MAKE_ENV+=		RT_LIB_SCHED=${RT_LIB_SCHED}
SUBST_CLASSES+=	rtlib
SUBST_STAGE.rtlib=	pre-configure
SUBST_FILES.rtlib=	libvisual.pc.in
SUBST_VARS.rtlib=	RT_LIB_SCHED

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${MACHINE_ARCH} == "i386"
.  if ${CC_VERSION:Mgcc*}
CPPFLAGS+=		-mmmx
.  endif
.endif

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
