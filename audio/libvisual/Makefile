# $NetBSD: Makefile,v 1.24 2013/06/13 14:25:30 joerg Exp $
#

DISTNAME=	libvisual-0.4.0
PKGREVISION=	4
CATEGORIES=	audio graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://localhost.nl/~synap/libvisual-wiki/
COMMENT=	Abstraction library for applications and audio visualisation plugins

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config msgfmt

PKGCONFIG_OVERRIDE+=	${WRKSRC}/libvisual.pc.in

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
RT_LIB_SCHED=		-lrt
.else
RT_LIB_SCHED=		# empty
.endif
MAKE_ENV+=		RT_LIB_SCHED=${RT_LIB_SCHED}
SUBST_CLASSES+=	rtlib
SUBST_STAGE.rtlib=	post-patch
SUBST_FILES.rtlib=	libvisual.pc.in
SUBST_VARS.rtlib=	RT_LIB_SCHED

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${MACHINE_ARCH} == "i386"
.  if !empty(CC_VERSION:Mgcc*)
CPPFLAGS+=		-mmmx
.  endif
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
