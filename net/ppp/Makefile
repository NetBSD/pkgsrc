# $NetBSD: Makefile,v 1.5 2002/05/07 23:48:48 hubertf Exp $

DISTNAME=		ppp-2.3.11
CATEGORIES=		net
MASTER_SITES=		ftp://cs.anu.edu.au/pub/software/ppp/

MAINTAINER=		tron@netbsd.org
COMMENT=		Point-to-Point Protocol for Internet connections over serial lines

ONLY_FOR_PLATFORM=	NetBSD-*-*

CONFLICTS+=		ppp-mppe-2.*

HAS_CONFIGURE=		yes
MANCOMPRESSED_IF_MANZ=	yes

MAKE_ENV+=		BINDIR=${PREFIX}/sbin \
			MANDIR=${PREFIX}/man \
			MANINSTALL="maninstall catinstall"

.include "../../mk/bsd.pkg.mk"
