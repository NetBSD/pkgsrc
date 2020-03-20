# $NetBSD: Makefile,v 1.20 2020/03/20 11:58:19 nia Exp $

DISTNAME=		steghide-0.5.1
PKGREVISION=		7
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=steghide/}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://steghide.sourceforge.net/
COMMENT=		Hides data (steganography) in audio or graphics files

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++03
USE_TOOLS+=		msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
