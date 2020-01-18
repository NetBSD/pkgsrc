# $NetBSD: Makefile,v 1.16 2020/01/18 23:30:26 rillig Exp $
#

DISTNAME=	dlcompat-20030629
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fink/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://fink.sourceforge.net/
COMMENT=	Library for dlopen() emulation on Darwin

ONLY_FOR_PLATFORM=	Darwin-[56].*-*

GNU_CONFIGURE=		yes

CONFLICTS=		man-pages-[0-9]*

.include "../../mk/bsd.pkg.mk"
