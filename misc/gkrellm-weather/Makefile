# $NetBSD: Makefile,v 1.14 2004/10/03 00:12:58 tv Exp $

DISTNAME=       gkrellweather-2.0.6
PKGNAME=        gkrellm-weather-2.0.6
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tripledes@eslack.org
HOMEPAGE=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
COMMENT=	Gkrellm2 weather plugin

DEPENDS+=       wget>=1.8:../../net/wget
BUILD_USES_MSGFMT=      YES

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES
ALL_TARGET=		gkrellweather.so

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
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
