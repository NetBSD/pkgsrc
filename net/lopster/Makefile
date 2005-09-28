# $NetBSD: Makefile,v 1.16 2005/09/28 20:52:24 rillig Exp $
#

DISTNAME=	lopster-1.2.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lopster/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lopster.sourceforge.net/
COMMENT=	Yet another Gtk+ Napster clone

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

post-extract:
	${RM} -fr ${WRKSRC}/intl

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
