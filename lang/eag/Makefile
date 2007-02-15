# $NetBSD: Makefile,v 1.7 2007/02/15 22:29:52 joerg Exp $

DISTNAME=		eag-2.3
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.ru.nl/pub/eag/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jaapboen@sci.kun.nl
HOMEPAGE=		http://www.cs.ru.nl/~kees/eag/
COMMENT=		Transducer generator using affix grammars

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
