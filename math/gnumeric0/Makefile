# $NetBSD: Makefile,v 1.24 2004/04/25 23:38:43 snj Exp $
#

DISTNAME=		gnumeric-0.75
PKGREVISION=		11
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnumeric/0.75/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/gnumeric/
COMMENT=		Powerful and easy to use spreadsheet program from the GNOME project

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
USE_PERL5=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-guile		# needs CVS-only guile-1.5
CONFIGURE_ARGS+=	--without-python
LIBS+=      		-lunicode

pre-configure:
	for i in ${WRKSRC}/plugins/*/Makefile.in ; do			\
		${SED} <$$i >$$i.fixed					\
		  -e 's/^\(COMPILE.*\)\\$$/\1 $${EXTRA_GNOME_CFLAGS} \\/' \
		  -e 's/^\(COMPILE.*[^\\]\)$$/\1 $${EXTRA_GNOME_CFLAGS}/' && \
		${MV} $$i.fixed $$i ;					\
	done

.include "../../converters/psiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libole2/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/libunicode/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
