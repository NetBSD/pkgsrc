# $NetBSD: Makefile,v 1.12 2003/03/09 06:05:57 dmcmahill Exp $
#

DISTNAME=		libgdgeda-2.0.9
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Modified version of the gd packages for use with gEDA

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
