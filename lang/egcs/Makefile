# $NetBSD: Makefile,v 1.9 2003/07/23 17:17:57 seb Exp $
#

DISTNAME=		egcs-1.1.2
CATEGORIES=		lang
MASTER_SITES=		ftp://egcs.cygnus.com/pub/egcs/releases/egcs-1.1.2/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://egcs.cygnus.com/index.html
COMMENT=		The experimental GNU compiler suite

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

PREFIX=			${LOCALBASE}/egcs

MAKE_ENV+=		CPPFLAGS=

ALL_TARGET=		bootstrap

USE_NEW_TEXINFO=	YES
INFO_FILES=		cpp.info g77.info gcc.info

.include "../../mk/bsd.pkg.mk"
