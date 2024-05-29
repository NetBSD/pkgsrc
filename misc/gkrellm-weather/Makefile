# $NetBSD: Makefile,v 1.93 2024/05/29 16:33:31 adam Exp $

DISTNAME=	gkrellweather-2.0.7
PKGNAME=	gkrellm-weather-2.0.7
PKGREVISION=	63
CATEGORIES=	misc
#MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tripledes@eslack.org
#HOMEPAGE=	http://kmlinux.fjfi.cvut.cz/~makovick/gkrellm/
COMMENT=	Gkrellm2 weather plugin
LICENSE=	gnu-gpl-v2

DEPENDS+=	wget>=1.8:../../net/wget

USE_TOOLS+=		gmake msgfmt perl:run pkg-config
USE_PKGLOCALEDIR=	YES
REPLACE_PERL=		GrabWeather
BUILD_TARGET=		gkrellweather.so

LOCALEDIR=		${PREFIX}/${PKGLOCALEDIR}/locale
INSTALLATION_DIRS=	bin lib lib/gkrellm2/plugins

MAKE_ENV+=	LOCALEDIR=${LOCALEDIR}
MAKE_ENV+=	enable_nls=1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/GrabWeather ${DESTDIR}${PREFIX}/bin
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
