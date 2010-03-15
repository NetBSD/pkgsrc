# $NetBSD: Makefile,v 1.13 2010/03/15 02:39:36 schmonz Exp $
#

DISTNAME=	dlcompat-20030629
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fink/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://fink.sourceforge.net/
COMMENT=	Library for dlopen() emulation on Darwin

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	Darwin-[56].*-*

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
