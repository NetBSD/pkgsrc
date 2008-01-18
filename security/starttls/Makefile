# $NetBSD: Makefile,v 1.2 2008/01/18 05:09:42 tnn Exp $
#

DISTNAME=		starttls-0.10
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://opaopa.org/pub/elisp/

MAINTAINER=		fun@naobsd.org
HOMEPAGE=		ftp://opaopa.org/pub/elisp/
COMMENT=		Simple wrapper program for STARTTLS on emacsen

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../mk/emacs.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
