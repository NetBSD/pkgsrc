# $NetBSD: Makefile,v 1.2 2008/07/25 13:59:39 obache Exp $
#

DISTNAME=	libmpcdec-1.2.6
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musepack.net/
COMMENT=	Portable Musepack decoder library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	include/mpcdec

.include "../../mk/bsd.pkg.mk"
