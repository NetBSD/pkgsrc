# $NetBSD: Makefile,v 1.4 2003/05/02 13:13:46 wiz Exp $
#

DISTNAME=		libirc-0.2
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		http://www.cs.kau.se/~jorgen/software/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.kau.se/~jorgen/software/
COMMENT=		libirc is a C-library for the IRC protocol

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
