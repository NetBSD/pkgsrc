# $NetBSD: Makefile,v 1.5 2012/04/15 22:07:37 wiz Exp $

DISTNAME=		clucene-core-0.9.21b
PKGNAME=		lib${DISTNAME:S/-core-/-/}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clucene/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://clucene.sourceforge.net/index.php/Main_Page
COMMENT=		Text search engine written in C++
LICENSE=		gnu-lgpl-v2.1 OR apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../mk/bsd.pkg.mk"
