# $NetBSD: Makefile,v 1.23 2016/12/07 10:54:35 wiz Exp $

DISTNAME=		hal-info-20091130
PKGREVISION=		5
CATEGORIES=		sysutils
MASTER_SITES=		http://hal.freedesktop.org/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://hal.freedesktop.org/
COMMENT=		FreeDesktop hardware abstraction layer (info subpackage)
LICENSE=		gnu-gpl-v2 # OR Academic-Free-License-v2.1

# TEST_DEPENDS
TOOL_DEPENDS+=		libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
