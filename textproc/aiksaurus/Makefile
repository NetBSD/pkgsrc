# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:17 tv Exp $
#

DISTNAME=	aiksaurus-1.0.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aiksaurus/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://aiksaurus.sourceforge.net/
COMMENT=	English-language thesaurus

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=		--without-gtk
PKGCONFIG_OVERRIDE=	base/aiksaurus-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
