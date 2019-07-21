# $NetBSD: Makefile,v 1.12 2019/07/21 22:23:58 wiz Exp $

DISTNAME=	suil-0.10.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/suil/
COMMENT=	Lightweight C library for loading and wrapping LV2 plugin UIs
LICENSE=	isc

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	suil.pc.in

WAF_ENV+=	CC=${CC:Q}
WAF_ENV+=	CFLAGS=${CFLAGS:Q}
WAF_ENV+=	CXX=${CXX:Q}
WAF_ENV+=	CXXFLAGS=${CXXFLAGS:Q}
WAF_ENV+=	DESTDIR=${DESTDIR}
WAF_ENV+=	LINKFLAGS=${LDFLAGS:Q}
WAF_ENV+=	PATH=${PATH:Q}
WAF_ENV+=	PREFIX=${PREFIX}
.if defined(MAKE_JOBS)
WAF_ENV+=	JOBS=${MAKE_JOBS}
.endif

# Kludge to support rst2man on Mac OS X, PR pkg/49921
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
WAF_ENV+=	LC_ALL="en_US.UTF-8"
.endif

WAF_ARGS=	--mandir=${PREFIX}/${PKGMANDIR}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${WAF_ENV} ./waf ${WAF_ARGS} ${WAF_CONFIGURE_ARGS} configure

do-build:
	cd ${WRKSRC} && ${SETENV} ${WAF_ENV} ./waf ${WAF_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${WAF_ENV} ./waf ${WAF_ARGS} install

BUILDLINK_API_DEPENDS.lv2+=	lv2>=1.12.0
.include "../../audio/lv2/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
