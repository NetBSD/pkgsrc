# $NetBSD: Makefile,v 1.2 2001/02/16 13:51:30 wiz Exp $
#

DISTNAME=		libirc-0.2
CATEGORIES=		chat
MASTER_SITES=		http://www.cs.kau.se/~jorgen/software/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.kau.se/~jorgen/software/
COMMENT=		libirc is a C-library for the IRC protocol

DEPENDS+=		glib>=1.2.6:../../devel/glib

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
