# $NetBSD: Makefile,v 1.71 2003/05/02 11:55:44 wiz Exp $
#

DISTNAME=		gnumeric-1.0.13
PKGREVISION=	1
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnumeric/1.0/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/gnumeric/
COMMENT=		Spreadsheet program from the GNOME project

# for Python support a shared libpython is required but not provided yet
#BUILD_DEPENDS+=		python>=2.0:../../lang/python

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_PERL5=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-psiconv
LIBS+=      		-lunicode

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

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
