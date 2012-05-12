# $NetBSD: Makefile,v 1.14 2012/05/12 07:37:51 wiz Exp $
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

CONFLICTS=		man-pages-[0-9]*

.include "../../mk/bsd.pkg.mk"
