# $NetBSD: Makefile,v 1.28 2008/01/18 05:08:34 tnn Exp $

DISTNAME=	gkrellweather-2.0.7
PKGNAME=	gkrellm-weather-2.0.7
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tripledes@eslack.org
HOMEPAGE=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
COMMENT=	Gkrellm2 weather plugin

DEPENDS+=	wget>=1.8:../../net/wget

USE_TOOLS+=		gmake msgfmt perl:run pkg-config
USE_PKGLOCALEDIR=	YES
BUILD_TARGET=		gkrellweather.so

MAKE_ENV+=	LOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale \
		enable_nls=1

pre-build:
	${MV} ${WRKSRC}/GrabWeather ${WRKSRC}/GrabWeather.orig
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig
	${SED} -e "s|/usr/local|${PREFIX}|" \
	${WRKSRC}/Makefile.orig > ${WRKSRC}/Makefile
	${SED}  -e "s|/usr/bin/perl|${PERL5}|" \
	${WRKSRC}/GrabWeather.orig > ${WRKSRC}/GrabWeather

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
