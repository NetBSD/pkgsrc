# $NetBSD: Makefile,v 1.9 2007/10/02 19:03:11 agc Exp $

DISTNAME=		steghide-0.5.1
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=steghide/}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://steghide.sourceforge.net/
COMMENT=		Hides data (steganography) in audio or graphics files

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
