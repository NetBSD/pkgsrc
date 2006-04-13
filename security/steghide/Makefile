# $NetBSD: Makefile,v 1.6 2006/04/13 18:23:37 jlam Exp $

DISTNAME=		steghide-0.5.1
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=steghide/}

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://steghide.sourceforge.net/
COMMENT=		Steganography program

GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
