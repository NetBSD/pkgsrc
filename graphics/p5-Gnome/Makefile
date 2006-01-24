# $NetBSD: Makefile,v 1.5 2006/01/24 07:32:16 wiz Exp $
#

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gnome-${GTKPERL_VERSION}
PKGREVISION=	3

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Perl bindings for Gnome

DEPENDS+=	p5-Gdk-Imlib-${GTKPERL_VERSION}nb1:../../graphics/p5-Gdk-Imlib

MAKE_PARAMS=	INSTALLMAN3DIR=${PREFIX}/man/man3
PERL5_PACKLIST=	auto/Gnome/.packlist

SUBPACKAGE=	Gnome

pre-configure:
	cd ${GTKDIR}/../GdkImlib && ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL
	cd ${GTKDIR}/../GdkImlib && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} -f ${MAKEFILE} ${BUILD_TARGET}

.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
