# $NetBSD: Makefile,v 1.13 2008/07/14 12:55:59 joerg Exp $
#

DISTNAME=		libirc-0.2
PKGREVISION=		2
CATEGORIES=		chat
MASTER_SITES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
# HOMEPAGE=		http://www.cs.kau.se/~jorgen/software/
COMMENT=		C library for the IRC protocol

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
