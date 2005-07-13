# $NetBSD: Makefile,v 1.2 2005/07/13 18:01:31 jlam Exp $
#

.include "../../x11/p5-gtk/Makefile.common"

PKGNAME=	p5-Gnome-${GTKPERL_VERSION}

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Perl bindings for Gnome

DEPENDS+=	p5-Gdk-Imlib-${GTKPERL_VERSION}:../../graphics/p5-Gdk-Imlib

MAKE_PARAMS=	INSTALLMAN3DIR=${PREFIX}/man/man3
PERL5_PACKLIST=	auto/Gnome/.packlist

SUBPACKAGE=	Gnome

pre-configure:
	cd ${GTKDIR}/../GdkImlib && ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL
	cd ${GTKDIR}/../GdkImlib && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} -f ${MAKEFILE} ${BUILD_TARGET}

.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/p5-gtk/Makefile.subpackage"
