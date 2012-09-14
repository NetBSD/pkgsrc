# $NetBSD: Makefile,v 1.10 2012/09/14 13:20:22 cheusov Exp $
#

DISTNAME=		starttls-0.10
PKGREVISION=		6
CATEGORIES=		security
MASTER_SITES=		ftp://opaopa.org/pub/elisp/

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		ftp://opaopa.org/pub/elisp/
COMMENT=		Simple wrapper program for STARTTLS on emacsen
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

MAKE_FLAGS=		lisp_LISP=

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
