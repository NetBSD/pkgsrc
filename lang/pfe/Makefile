# $NetBSD: Makefile,v 1.18 2019/08/11 13:21:23 wiz Exp $

DISTNAME=	pfe-0.33.71
PKGREVISION=	13
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

MAKE_JOBS_SAFE=	no
BUILD_TARGET=	all mans docs
INSTALL_TARGET=	install install-mans install-docs
TEST_TARGET=	tests

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto	# documentation
PYTHON_FOR_BUILD_ONLY=	tool

.include "../../lang/python/pyversion.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
