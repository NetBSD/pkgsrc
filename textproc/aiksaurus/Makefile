# $NetBSD: Makefile,v 1.4 2003/09/26 20:51:41 jmmv Exp $
#

DISTNAME=	aiksaurus-1.0.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aiksaurus/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://aiksaurus.sourceforge.net/
COMMENT=	English-language thesaurus

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=		--without-gtk
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/base/aiksaurus-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
