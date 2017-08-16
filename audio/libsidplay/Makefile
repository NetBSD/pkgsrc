# $NetBSD: Makefile,v 1.27 2017/08/16 20:21:03 wiz Exp $
#

DISTNAME=	libsidplay-1.36.59
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://tnsp.org/xs-files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tnsp.org/?p=libsidplay1
COMMENT=	Sidplay Library
LICENSE=	gnu-gpl-v2

CONFLICTS=	sidplay-1.36.*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
