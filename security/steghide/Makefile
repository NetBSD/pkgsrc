# $NetBSD: Makefile,v 1.4 2006/02/05 23:10:47 joerg Exp $

DISTNAME=		steghide-0.5.1
PKGREVISION=	2
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=steghide/}

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://steghide.sourceforge.net/
COMMENT=		Steganography program

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
