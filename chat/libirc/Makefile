# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 00:36:31 wiz Exp $
#

DISTNAME=		libirc-0.2
CATEGORIES=		chat
MASTER_SITES=		http://www.cs.kau.se/~jorgen/software/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.kau.se/~jorgen/software/

DEPENDS+=		glib>=1.2.6:../../devel/glib

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
