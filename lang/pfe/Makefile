# $NetBSD: Makefile,v 1.27 2023/08/14 05:24:45 wiz Exp $

DISTNAME=	pfe-0.33.71
PKGREVISION=	17
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfe/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://pfe.sourceforge.net/
COMMENT=	Portable FORTH Environment

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-testmodule
USE_LIBTOOL=	yes
USE_TOOLS+=	perl pkg-config
MAKE_ENV+=	SHELL=${CONFIG_SHELL}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet as of 0.33.71

MAKE_JOBS_SAFE=	no
BUILD_TARGET=	all mans docs
INSTALL_TARGET=	install install-mans install-docs
TEST_TARGET=	tests

TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto	# documentation
PYTHON_FOR_BUILD_ONLY=	tool

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--warn-common

.include "../../lang/python/pyversion.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
