# $NetBSD: Makefile,v 1.1.1.1 1999/03/30 05:00:33 garbled Exp $

DISTNAME=		freetype-1.1.full
PKGNAME=		freetype-1.1
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.freetype.org/pub/freetype/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.freetype.org

DEPENDS+=		gettext-0.10:../../misc/gettext

WRKSRC=			${WRKDIR}/${PKGNAME}

USE_X11=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-locale-dir=${PREFIX}/share/locale

.include "../../mk/bsd.pkg.mk"
