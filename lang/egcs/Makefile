# $NetBSD: Makefile,v 1.2 1999/05/24 20:39:43 tv Exp $
#

DISTNAME=		egcs-1.1.2
CATEGORIES=		lang
MASTER_SITES=		ftp://egcs.cygnus.com/pub/egcs/releases/egcs-1.1.2/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://egcs.cygnus.com/index.html

GNU_CONFIGURE=		yes

NOT_FOR_PLATFORM=	NetBSD-*-*	# In NetBSD base system

PREFIX=			${LOCALBASE}/egcs

MAKE_ENV+=		CPPFLAGS=

ALL_TARGET=		bootstrap

INFO_FILES=		cpp.info g77.info gcc.info

.include "../../mk/bsd.pkg.mk"
