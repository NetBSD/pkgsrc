# $NetBSD: Makefile,v 1.63 2002/12/01 15:56:54 salo Exp $
#

DISTNAME=		gnumeric-1.0.10
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnumeric/1.0/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/gnumeric/
COMMENT=		Spreadsheet program from the GNOME project

# wctype.h is found on NetBSD 1.5R and later
ONLY_FOR_PLATFORM=	NetBSD-1.5[R-Z]-* NetBSD-1.5Z[A-Z]-* NetBSD-1.[6-9]*-* SunOS-*-*

# for Python support a shared libpython is required but not provided yet
#BUILD_DEPENDS+=		python>=2.0:../../lang/python

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_PERL5=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-guile		# needs CVS-only guile-1.5
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-psiconv
CONFIGURE_ARGS+=	--localstatedir=${SCROLLKEEPER_DATADIR}
LIBS+=      		-lunicode

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/libole2/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
