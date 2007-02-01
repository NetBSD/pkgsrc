# $NetBSD: Makefile,v 1.14 2007/02/01 19:07:23 drochner Exp $
#

DISTNAME=	check-0.9.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=check/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://check.sourceforge.net/
COMMENT=	Unit test framework for C

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-plain-docdir
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
INFO_FILES=	yes
PKGCONFIG_OVERRIDE=	check.pc.in

.include "../../mk/bsd.pkg.mk"
