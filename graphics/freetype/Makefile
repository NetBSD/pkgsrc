# $NetBSD: Makefile,v 1.3 1999/04/01 18:53:17 garbled Exp $

DISTNAME=		freetype-1.1.full
PKGNAME=		freetype-1.1
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.freetype.org/pub/freetype/old/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.freetype.org

DEPENDS+=		gettext-0.10:../../devel/gettext

WRKSRC=			${WRKDIR}/${PKGNAME}

USE_X11=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-locale-dir=${PREFIX}/share/locale

.include "../../mk/bsd.pkg.mk"
