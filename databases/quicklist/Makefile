# $NetBSD: Makefile,v 1.4 2001/01/04 02:53:51 wiz Exp $
#

DISTNAME=	quicklist-0.8.6
CATEGORIES=	databases x11
MASTER_SITES=	ftp://ftp.quicklist.org/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.quicklist.org/

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=	yes
USE_LIBINTL=	yes
USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"
