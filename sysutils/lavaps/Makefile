# $NetBSD: Makefile,v 1.26 2006/06/08 20:08:23 joerg Exp $
#

DISTNAME=	lavaps-1.20
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/
COMMENT=	Lava lamp of currently running processes

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-additional-includes=-I${LOCALBASE:Q}/include \
		--with-additional-libs=-L${LOCALBASE:Q}/lib \
		--with-tcl-ver=8.3.2 \
		--with-tk-ver=8.3.2 \
		--with-tcltk-lib-suffix-type=nodot

.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
