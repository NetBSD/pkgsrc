# $NetBSD: Makefile,v 1.1.1.1 2004/07/21 03:08:08 snj Exp $

DISTNAME=		steghide-0.5.1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=steghide/}

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://steghide.sourceforge.net/
COMMENT=		Steganography program

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
