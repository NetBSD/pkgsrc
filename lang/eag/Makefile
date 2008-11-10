# $NetBSD: Makefile,v 1.10 2008/11/10 17:21:36 wiz Exp $

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

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
