# $NetBSD: Makefile,v 1.4 2001/09/20 22:39:43 hubertf Exp $

DISTNAME=		ppp-2.3.11
CATEGORIES=		net
MASTER_SITES=		ftp://cs.anu.edu.au/pub/software/ppp/

MAINTAINER=		tron@netbsd.org
COMMENT=		Point-to-Point Protocol for Internet connections over serial lines

ONLY_FOR_PLATFORM=	NetBSD-*-*

HAS_CONFIGURE=		yes
MANCOMPRESSED_IF_MANZ=	yes

MAKE_ENV+=		BINDIR=${PREFIX}/sbin \
			MANDIR=${PREFIX}/man \
			MANINSTALL="maninstall catinstall"

.include "../../mk/bsd.pkg.mk"
