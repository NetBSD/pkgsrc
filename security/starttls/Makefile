# $NetBSD: Makefile,v 1.13 2014/02/12 23:18:37 tron Exp $
#

DISTNAME=		starttls-0.10
PKGREVISION=		8
CATEGORIES=		security
MASTER_SITES=		ftp://opaopa.org/pub/elisp/

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		ftp://opaopa.org/pub/elisp/
COMMENT=		Simple wrapper program for STARTTLS on emacsen
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

MAKE_FLAGS=		lisp_LISP=

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
