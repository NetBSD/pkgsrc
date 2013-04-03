# $NetBSD: Makefile,v 1.13 2013/04/03 13:26:44 jaapb Exp $

DISTNAME=		eag-2.6
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.ru.nl/pub/eag/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jaapb@NetBSD.org
HOMEPAGE=		http://www.cs.ru.nl/~kees/eag/
COMMENT=		Transducer generator using affix grammars
LICENSE=		eag-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--docdir ${PREFIX}/share/doc/eag

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${PREFIX:Q}/lib
.endif

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
