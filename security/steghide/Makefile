# $NetBSD: Makefile,v 1.8 2006/08/13 23:32:22 wiz Exp $

DISTNAME=		steghide-0.5.1
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=steghide/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://steghide.sourceforge.net/
COMMENT=		Steganography program

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
