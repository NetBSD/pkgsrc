# $NetBSD: Makefile,v 1.8 2012/07/17 18:08:02 cheusov Exp $
#

DISTNAME=		starttls-0.10
PKGREVISION=		5
CATEGORIES=		security
MASTER_SITES=		ftp://opaopa.org/pub/elisp/

MAINTAINER=		fun@naobsd.org
HOMEPAGE=		ftp://opaopa.org/pub/elisp/
COMMENT=		Simple wrapper program for STARTTLS on emacsen
LICENSE=		gnu-gpl-v2

DEPENDS=		emacs-[0-9]*:../../editors/emacs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

MAKE_FLAGS=		lisp_LISP=

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
