# $NetBSD: Makefile,v 1.9 2006/05/26 19:27:27 joerg Exp $
#

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gnome-${GTKPERL_VERSION}
PKGREVISION=	6

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Perl bindings for Gnome

DEPENDS+=	p5-Gdk-Imlib-${GTKPERL_VERSION}{,nb}:../../graphics/p5-Gdk-Imlib

PERL5_PACKLIST=	auto/Gnome/.packlist
SUBPACKAGE=	Gnome

pre-configure:
	cd ${GTKDIR}/../GdkImlib && ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL
	cd ${GTKDIR}/../GdkImlib && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} -f ${MAKEFILE} ${BUILD_TARGET}

.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
