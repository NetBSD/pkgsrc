# $NetBSD: Makefile,v 1.10 2004/05/09 12:54:00 grant Exp $
#

DISTNAME=	dlcompat-20030629
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fink/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://fink.sourceforge.net/
COMMENT=	Library for dlopen() emulation on Darwin

ONLY_FOR_PLATFORM=	Darwin-*-*

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
