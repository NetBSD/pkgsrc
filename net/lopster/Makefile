# $NetBSD: Makefile,v 1.11 2004/04/25 08:36:43 snj Exp $
#

DISTNAME=	lopster-1.2.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lopster/}

MAINTAINER=	ad@NetBSD.org
HOMEPAGE=	http://lopster.sourceforge.net/
COMMENT=	Yet another Gtk+ Napster clone

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	# defined

post-extract:
	${RM} -fr ${WRKSRC}/intl

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
