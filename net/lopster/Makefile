# $NetBSD: Makefile,v 1.8 2003/07/13 13:52:56 wiz Exp $
#

DISTNAME=	lopster-1.2.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lopster/}

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://lopster.sourceforge.net/
COMMENT=	Yet another Gtk+ Napster clone

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	# defined

post-extract:
	${RM} -fr ${WRKSRC}/intl

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
