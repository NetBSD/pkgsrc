# $NetBSD: Makefile,v 1.7 2001/06/11 06:34:19 jlam Exp $
#

DISTNAME=	gwave-20001123
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.unc.edu/~tell/dist/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.cs.unc.edu/~tell/gwave/
COMMENT=	viewer for spice-like simulator output and other analog data

DEPENDS+=	guile-gtk>=0.19:../../devel/guile-gtk
DEPENDS+=	plotutils-*:../../graphics/plotutils

GNU_CONFIGURE=	YES
# LDFLAGS to get -lreadline
# CPPFLAGS to get -I${LOCALBASE}/include for readline/readline.h
CPPFLAGS+=	-I${LOCALBASE}/include

post-extract:
	${CP} ${FILESDIR}/sp2sp.1 ${WRKSRC}/doc/sp2sp.1

.include "../../mk/bsd.pkg.mk"
