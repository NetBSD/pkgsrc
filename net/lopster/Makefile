# $NetBSD: Makefile,v 1.14 2005/04/11 21:46:49 tv Exp $
#

DISTNAME=	lopster-1.2.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lopster/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lopster.sourceforge.net/
COMMENT=	Yet another Gtk+ Napster clone

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	# defined

post-extract:
	${RM} -fr ${WRKSRC}/intl

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
