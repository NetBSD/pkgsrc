# $NetBSD: Makefile,v 1.22 2023/08/02 19:21:57 nia Exp $

DISTNAME=		steghide-0.5.1
PKGREVISION=		7
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=steghide/}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://steghide.sourceforge.net/
COMMENT=		Hides data (steganography) in audio or graphics files
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
