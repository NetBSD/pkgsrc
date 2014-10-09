# $NetBSD: Makefile,v 1.16 2014/10/09 14:07:01 wiz Exp $
#

DISTNAME=	aiksaurus-1.2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aiksaurus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aiksaurus.sourceforge.net/
COMMENT=	English-language thesaurus

USE_LIBTOOL=	YES
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-gtk
PKGCONFIG_OVERRIDE=	base/aiksaurus-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
