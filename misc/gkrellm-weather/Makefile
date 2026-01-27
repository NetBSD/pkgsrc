# $NetBSD: Makefile,v 1.105 2026/01/27 08:40:08 wiz Exp $

DISTNAME=	gkrellweather-2.0.8
PKGNAME=	${DISTNAME:S/gkrellweather/gkrellm-weather/}
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tripledes@eslack.org
COMMENT=	Gkrellm2 weather plugin
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-LWP-Protocol-https-[0-9]*:../../www/p5-LWP-Protocol-https

USE_TOOLS+=		gmake msgfmt perl:run pkg-config
USE_PKGLOCALEDIR=	YES
REPLACE_PERL=		GrabWeather
BUILD_TARGET=		gkrellweather.so

LOCALEDIR=		${PREFIX}/${PKGLOCALEDIR}/locale
INSTALLATION_DIRS=	lib libexec lib/gkrellm2/plugins

MAKE_ENV+=	LOCALEDIR=${LOCALEDIR}
MAKE_ENV+=	enable_nls=1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/GrabWeather ${DESTDIR}${PREFIX}/libexec
	${INSTALL_LIB} ${WRKSRC}/gkrellweather.so \
	    ${DESTDIR}${PREFIX}/lib/gkrellm2/plugins
	set -e; cd ${WRKSRC}/po && for f in *.mo; do \
	    base=`basename "$$f" .mo`;					\
	    modir=${DESTDIR}${LOCALEDIR}/"$${base}"/LC_MESSAGES;	\
	    ${INSTALL_DATA_DIR} "$${modir}";				\
	    ${INSTALL_DATA} "$$f" "$${modir}"/gkrellweather.mo;		\
	done

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
