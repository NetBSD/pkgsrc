# $NetBSD: Makefile,v 1.10 2004/01/24 14:50:05 grant Exp $
#

DISTNAME=	lopster-1.2.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lopster/}

MAINTAINER=	ad@NetBSD.org
HOMEPAGE=	http://lopster.sourceforge.net/
COMMENT=	Yet another Gtk+ Napster clone

USE_BUILDLINK2=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	# defined

post-extract:
	${RM} -fr ${WRKSRC}/intl

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
