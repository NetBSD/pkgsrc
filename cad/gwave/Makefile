# $NetBSD: Makefile,v 1.11 2002/05/18 17:47:59 dmcmahill Exp $
#

DISTNAME=	gwave-20020122
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.unc.edu/~tell/dist/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.cs.unc.edu/~tell/gwave/
COMMENT=	viewer for spice-like simulator output and other analog data

DEPENDS+=	guile-gtk>=0.19:../../devel/guile-gtk
DEPENDS+=	plotutils>=2.4.1nb1:../../graphics/plotutils

GNU_CONFIGURE=	YES
# LDFLAGS to get -lreadline
# CPPFLAGS to get -I${LOCALBASE}/include for readline/readline.h
CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
