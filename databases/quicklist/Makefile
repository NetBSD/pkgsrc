# $NetBSD: Makefile,v 1.1.1.1 2000/04/26 06:36:31 garbled Exp $
#

DISTNAME=		quicklist-0.8.6
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.quicklist.org/
MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.quicklist.org

DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		gettext-0.10.35:../../devel/gettext

GNU_CONFIGURE=		yes
CFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
