# $NetBSD: Makefile,v 1.5 2002/11/20 10:37:17 schmonz Exp $
#

DISTNAME=	dlcompat-20021117
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fink/}

MAINTAINER=	schmonz@netbsd.org
HOMEPAGE=	http://fink.sourceforge.net/
COMMENT=	Library for dlopen() emulation on Darwin

# dlcompat is needed to bootstrap buildlink2 on Darwin (via bash).
USE_BUILDLINK2=		no
ONLY_FOR_PLATFORM=	Darwin-*-*

GNU_CONFIGURE=	# defined

.include "../../mk/bsd.pkg.mk"
