# $NetBSD: Makefile,v 1.4 2001/02/17 09:07:04 agc Exp $
#

DISTNAME=		egcs-1.1.2
CATEGORIES=		lang
MASTER_SITES=		ftp://egcs.cygnus.com/pub/egcs/releases/egcs-1.1.2/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://egcs.cygnus.com/index.html
COMMENT=		the experimental GNU compiler suite

GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

PREFIX=			${LOCALBASE}/egcs

MAKE_ENV+=		CPPFLAGS=

ALL_TARGET=		bootstrap

INFO_FILES=		cpp.info g77.info gcc.info

.include "../../mk/bsd.pkg.mk"
