# $NetBSD: Makefile,v 1.3 1999/07/02 08:46:51 agc Exp $
#

DISTNAME=		egcs-1.1.2
CATEGORIES=		lang
MASTER_SITES=		ftp://egcs.cygnus.com/pub/egcs/releases/egcs-1.1.2/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://egcs.cygnus.com/index.html

GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

PREFIX=			${LOCALBASE}/egcs

MAKE_ENV+=		CPPFLAGS=

ALL_TARGET=		bootstrap

INFO_FILES=		cpp.info g77.info gcc.info

.include "../../mk/bsd.pkg.mk"
