# $NetBSD: Makefile,v 1.9 2001/10/23 01:39:16 dmcmahill Exp $
#

DISTNAME=	gwave-20011021
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.unc.edu/~tell/dist/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.cs.unc.edu/~tell/gwave/
COMMENT=	viewer for spice-like simulator output and other analog data

DEPENDS+=	guile-gtk>=0.19:../../devel/guile-gtk
DEPENDS+=	plotutils-[0-9]*:../../graphics/plotutils

GNU_CONFIGURE=	YES
# LDFLAGS to get -lreadline
# CPPFLAGS to get -I${LOCALBASE}/include for readline/readline.h
CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
