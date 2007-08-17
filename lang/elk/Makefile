# $NetBSD: Makefile,v 1.36 2007/08/17 22:27:15 joerg Exp $

DISTNAME=	elk-3.99.7
CATEGORIES=	lang
MASTER_SITES=	http://sam.zoy.org/elk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sam.zoy.org/elk/
COMMENT=	Embeddable Scheme interpreter

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		WITH_XAW=${ELK_AWK:Q}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
