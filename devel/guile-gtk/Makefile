# $NetBSD: Makefile,v 1.12 2003/05/02 11:54:31 wiz Exp $
#

DISTNAME=		guile-gtk-0.19
PKGREVISION=		2
CATEGORIES=		devel x11
MASTER_SITES=		http://www.ping.de/sites/zagadka/guile-gtk/download/ \
			http://erin.netpedia.net/download/ \
			http://erin.linuxbox.com/guile-gtk/download/ \
			http://linux.cem.itesm.mx/~jarios/guile-gtk/download/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.ping.de/sites/zagadka/guile-gtk/
COMMENT=		Library to make GTK accesible from guile

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--datadir=${GUILE14_PREFIX}/share
PLIST_SUBST+=		GUILE14_SUBDIR=${GUILE14_SUBDIR}
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

pre-build:
	cd ${WRKSRC}; for file in build-guile-gtk; do			\
		${SED}	-e "s,^exec guile,exec ${GUILE14},"		\
			$$file > $$file.new;				\
		${MV} -f $$file.new $$file;				\
	done

.include "../../lang/guile14/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
