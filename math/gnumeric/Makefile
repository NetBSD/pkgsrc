# $NetBSD: Makefile,v 1.79 2004/02/14 17:21:44 jlam Exp $
#

DISTNAME=		gnumeric-1.0.13
PKGREVISION=		5
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnumeric/1.0/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/gnumeric/
COMMENT=		Spreadsheet program from the GNOME project

DEPENDS+=		gnome1-dirs>=1.2:../../misc/gnome1-dirs
# for Python support a shared libpython is required but not provided yet
#BUILD_DEPENDS+=		python>=2.0:../../lang/python

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
USE_PERL5=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-psiconv
LIBS+=      		-lunicode

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/libole2/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"
.include "../../lang/guile/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"

.include "../../mk/bsd.pkg.mk"
