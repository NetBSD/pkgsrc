# $NetBSD: Makefile,v 1.14 2020/11/05 09:07:53 ryoon Exp $
#

DISTNAME=	doxymacs-1.8.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=doxymacs/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://doxymacs.sourceforge.net/
COMMENT=	Doxygen editing support for Emacs

.include "../../editors/emacs/modules.mk"

#
# "www/w3" (Emacs/W3) currently does not work with Emacs 22.  Emacs/W3
# is documented as a requirement for Doxymacs, but it appears that it
# is only used for the url-* support introduced in Emacs/W3.
# Fortunately, the url-* support from Emacs/W3 has been integrated
# into Emacs version 22.  The same support for XEmacs is available in
# editors/xemacs-packages.
#
.if ${EMACS_FLAVOR} == xemacs
DEPENDS+=	xemacs-packages-[0-9]*:../../editors/xemacs-packages
.elif ${EMACS_VERSION_MAJOR} <= 21
DEPENDS+=	w3-[0-9]*:../../www/w3
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		EMACS=${EMACS_BIN:Q}
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX:Q}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
