# $NetBSD: Makefile,v 1.6 1999/07/20 01:12:20 hubertf Exp $

DISTNAME=		freetype-1.1.full
PKGNAME=		freetype-1.1
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.freetype.org/pub/freetype/old/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.freetype.org/

DEPENDS+=		gettext-0.10.35:../../devel/gettext

WRKSRC=			${WRKDIR}/${PKGNAME}

USE_X11=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-locale-dir=${PREFIX}/share/locale
CFLAGS+=		-Wl,-L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
