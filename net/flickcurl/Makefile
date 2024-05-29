# $NetBSD: Makefile,v 1.46 2024/05/29 16:33:51 adam Exp $

DISTNAME=	flickcurl-1.26
PKGREVISION=	31
CATEGORIES=	net
MASTER_SITES=	http://download.dajobe.org/flickcurl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.dajobe.org/flickcurl/
COMMENT=	Flickr API library
LICENSE=	gnu-lgpl-v2.1 OR gnu-gpl-v2 OR apache-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

# XXX: Kludge to avoid uncoditionally pick up some gtkdoc-* tools if gtk-doc
# XXX: package is installed and then fails in the installation phase.
CONFIGURE_ENV+=		ac_cv_prog_GTKDOC_CHECK= \
			ac_cv_path_GTKDOC_CHECK_PATH= \
			ac_cv_path_GTKDOC_REBASE= \
			ac_cv_path_GTKDOC_MKPDF=

.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
