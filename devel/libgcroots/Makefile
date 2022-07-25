# $NetBSD: Makefile,v 1.8 2022/07/25 11:12:22 wiz Exp $

DISTNAME=	libgcroots-0.2.3
CATEGORIES=	devel
MASTER_SITES=	http://sigscheme.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/sigscheme/wikis/libgcroots.wiki
COMMENT=	Garbage collector supporting library
#LICENSE=	# See ${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	gcroots.pc.in

# This directory is used for c++ interface, but not build by default.
post-install:
	rmdir ${DESTDIR}${PREFIX}/include/libgcroots

.include "../../mk/bsd.pkg.mk"
