# $NetBSD: Makefile,v 1.1 2012/12/03 22:26:09 wiz Exp $

DISTNAME=		mp4v2-2.0.0
CATEGORIES=		multimedia
MASTER_SITES=		http://mp4v2.googlecode.com/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://code.google.com/p/mp4v2/
COMMENT=		Library for reading and modifying mp4 files
LICENSE=		mpl-1.1

CONFLICTS+=		mpeg4ip<1.5.0.1 libmp4v2-[0-9]*

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
MAKE_FILE=		GNUmakefile

.include "../../mk/bsd.pkg.mk"
