# $NetBSD: Makefile,v 1.1.1.1 2000/07/11 20:41:26 tron Exp $

DISTNAME=		ppp-2.3.11
CATEGORIES=		net
MASTER_SITES=		ftp://cs.anu.edu.au/pub/software/ppp/

MAINTAINER=		tron@netbsd.org

HAS_CONFIGURE=		yes
MANCOMPRESSED_IF_MANZ=	yes

MAKE_ENV+=		BINDIR=${PREFIX}/sbin \
			MANDIR=${PREFIX}/man \
			MANINSTALL="maninstall catinstall"

.include "../../mk/bsd.pkg.mk"
