# $NetBSD: Makefile,v 1.8 2003/07/21 16:54:01 martti Exp $
#

DISTNAME=		egcs-1.1.2
CATEGORIES=		lang
MASTER_SITES=		ftp://egcs.cygnus.com/pub/egcs/releases/egcs-1.1.2/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://egcs.cygnus.com/index.html
COMMENT=		The experimental GNU compiler suite

GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

PREFIX=			${LOCALBASE}/egcs

MAKE_ENV+=		CPPFLAGS=

ALL_TARGET=		bootstrap

INFO_FILES=		cpp.info g77.info gcc.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
