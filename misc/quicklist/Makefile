# $NetBSD: Makefile,v 1.1.1.1 1999/09/15 03:23:40 jlam Exp $
#

DISTNAME=	quicklist-0.8.2
CATEGORIES=	misc x11
MASTER_SITES=	ftp://ftp.quicklist.org/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.quicklist.org/

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	gtk+-1.2.4:../../x11/gtk

GNU_CONFIGURE=	yes
USE_X11BASE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include	# for libintl.h
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
