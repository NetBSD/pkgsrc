# $NetBSD: Makefile,v 1.2 2009/07/07 21:27:17 joerg Exp $

DISTNAME=		clucene-core-0.9.21
PKGREVISION=		1
PKGNAME=		lib${DISTNAME:S/-core-/-/}
CATEGORIES=		textproc

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clucene/}

MAINTAINER=		mkirby@NetBSD.org
HOMEPAGE=		http://clucene.sourceforge.net/index.php/Main_Page
COMMENT=		Text search engine written in C++

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	        gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_LIBTOOL=	        yes

.include "../../mk/bsd.pkg.mk"
