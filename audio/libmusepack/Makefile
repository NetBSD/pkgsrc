# $NetBSD: Makefile,v 1.5 2007/01/31 21:33:31 cbiere Exp $
#

DISTNAME=		libmpcdec-1.2.4
PKGNAME=		${DISTNAME:S/mpcdec/musepack/}
CATEGORIES=		audio
MASTER_SITES=		http://files.musepack.net/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.musepack.net/
COMMENT=		Portable Musepack decoder library

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS+=	include/mpcdec

.include "../../mk/bsd.pkg.mk"
