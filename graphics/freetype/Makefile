# $NetBSD: Makefile,v 1.8 1999/10/28 00:38:43 jlam Exp $

DISTNAME=		freetype-1.2
CATEGORIES=		graphics textproc
MASTER_SITES=		ftp://ftp.freetype.org/pub/freetype/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.freetype.org/

DEPENDS+=		gettext-0.10.35:../../devel/gettext

USE_X11=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-locale-dir=${PREFIX}/share/locale
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include	# libintl.h

.include "../../mk/bsd.pkg.mk"
