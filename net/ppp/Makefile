# $NetBSD: Makefile,v 1.2 2000/11/15 16:07:23 tron Exp $

DISTNAME=		ppp-2.3.11
CATEGORIES=		net
MASTER_SITES=		ftp://cs.anu.edu.au/pub/software/ppp/

MAINTAINER=		tron@netbsd.org

ONLY_FOR_PLATFORM=	NetBSD-1.4*-*

HAS_CONFIGURE=		yes
MANCOMPRESSED_IF_MANZ=	yes

MAKE_ENV+=		BINDIR=${PREFIX}/sbin \
			MANDIR=${PREFIX}/man \
			MANINSTALL="maninstall catinstall"

.include "../../mk/bsd.pkg.mk"
