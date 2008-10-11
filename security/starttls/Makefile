# $NetBSD: Makefile,v 1.4 2008/10/11 09:31:58 uebayasi Exp $
#

DISTNAME=		starttls-0.10
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://opaopa.org/pub/elisp/

MAINTAINER=		fun@naobsd.org
HOMEPAGE=		ftp://opaopa.org/pub/elisp/
COMMENT=		Simple wrapper program for STARTTLS on emacsen

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../editors/emacs/modules.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
