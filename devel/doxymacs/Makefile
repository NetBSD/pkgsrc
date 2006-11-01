# $NetBSD: Makefile,v 1.2 2006/11/01 07:09:53 dsainty Exp $
#

DISTNAME=	doxymacs-1.7.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=doxymacs/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://doxymacs.sourceforge.net/
COMMENT=	Doxygen editing support for Emacs

DEPENDS+=	w3-[0-9]*:../../www/w3

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	EMACS=${EMACS_BIN:Q}

.include "../../mk/emacs.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
