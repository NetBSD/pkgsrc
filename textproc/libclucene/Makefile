# $NetBSD: Makefile,v 1.6 2012/10/25 06:56:02 asau Exp $

DISTNAME=		clucene-core-0.9.21b
PKGNAME=		lib${DISTNAME:S/-core-/-/}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clucene/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://clucene.sourceforge.net/index.php/Main_Page
COMMENT=		Text search engine written in C++
LICENSE=		gnu-lgpl-v2.1 OR apache-2.0

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../mk/bsd.pkg.mk"
