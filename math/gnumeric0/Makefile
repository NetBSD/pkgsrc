# $NetBSD: Makefile,v 1.11 2002/12/01 15:56:56 salo Exp $
#

DISTNAME=		gnumeric-0.75
PKGREVISION=		4
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnumeric/0.75/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/gnumeric/
COMMENT=		Powerful and easy to use spreadsheet program from the GNOME project

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_PERL5=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-guile		# needs CVS-only guile-1.5
CONFIGURE_ARGS+=	--without-python
LIBS+=      		-lunicode

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-configure:
	for i in ${WRKSRC}/plugins/*/Makefile.in ; do			\
		${SED} <$$i >$$i.fixed					\
		  -e 's/^\(COMPILE.*\)\\$$/\1 $${EXTRA_GNOME_CFLAGS} \\/' \
		  -e 's/^\(COMPILE.*[^\\]\)$$/\1 $${EXTRA_GNOME_CFLAGS}/' && \
		${MV} $$i.fixed $$i ;					\
	done

.include "../../converters/psiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/libole2/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
