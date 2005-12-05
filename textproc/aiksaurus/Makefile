# $NetBSD: Makefile,v 1.12 2005/12/05 20:51:02 rillig Exp $
#

DISTNAME=	aiksaurus-1.2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aiksaurus/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://aiksaurus.sourceforge.net/
COMMENT=	English-language thesaurus

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	YES
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-gtk
PKGCONFIG_OVERRIDE=	base/aiksaurus-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
