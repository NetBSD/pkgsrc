# $NetBSD: Makefile,v 1.3 2003/05/02 11:54:05 wiz Exp $
#

DISTNAME=		libirc-0.2
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		http://www.cs.kau.se/~jorgen/software/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.kau.se/~jorgen/software/
COMMENT=		libirc is a C-library for the IRC protocol

DEPENDS+=		glib>=1.2.10nb4:../../devel/glib

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
