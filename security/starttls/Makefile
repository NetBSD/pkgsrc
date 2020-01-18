# $NetBSD: Makefile,v 1.15 2020/01/18 21:50:48 jperkin Exp $
#

DISTNAME=		starttls-0.10
PKGREVISION=		10
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
