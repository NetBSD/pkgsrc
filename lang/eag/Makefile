# $NetBSD: Makefile,v 1.11 2009/11/26 16:40:55 joerg Exp $

DISTNAME=		eag-2.3
PKGREVISION=		3
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.ru.nl/pub/eag/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jaapb@kerguelen.org
HOMEPAGE=		http://www.cs.ru.nl/~kees/eag/
COMMENT=		Transducer generator using affix grammars

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${PREFIX:Q}/lib
.endif

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
