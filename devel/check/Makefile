# $NetBSD: Makefile,v 1.15 2008/04/16 13:03:43 obache Exp $
#

DISTNAME=	check-0.9.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=check/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://check.sourceforge.net/
COMMENT=	Unit test framework for C

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-plain-docdir
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
INFO_FILES=	yes
PKGCONFIG_OVERRIDE=	check.pc.in

.include "../../mk/bsd.pkg.mk"
