# $NetBSD: Makefile,v 1.5 2002/07/14 01:34:40 rh Exp $
#

DISTNAME=		gnumeric-0.75
PKGREVISION=		2
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnumeric/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/gnumeric/
COMMENT=		Powerful and easy to use spreadsheet program from the GNOME project

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_PERL5=		YES
USE_BUILDLINK_ONLY=	YES

LDFLAGS+=      		-L${LOCALBASE}/lib
LDFLAGS+=      		-Wl,-R${LOCALBASE}/lib
LDFLAGS+=      		-lunicode
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--without-guile		# needs CVS-only guile-1.5
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-psiconv
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-configure:
	for i in ${WRKSRC}/plugins/*/Makefile.in ; do			\
		${SED} <$$i >$$i.fixed					\
		  -e 's/^\(COMPILE.*\)\\$$/\1 $${EXTRA_GNOME_CFLAGS} \\/' \
		  -e 's/^\(COMPILE.*[^\\]\)$$/\1 $${EXTRA_GNOME_CFLAGS}/' && \
		${MV} $$i.fixed $$i ;					\
	done

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../devel/libole2/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
