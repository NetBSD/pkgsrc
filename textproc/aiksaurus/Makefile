# $NetBSD: Makefile,v 1.19 2016/08/03 10:23:27 adam Exp $
#

DISTNAME=	aiksaurus-1.2.1
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aiksaurus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aiksaurus.sourceforge.net/
COMMENT=	English-language thesaurus

USE_LIBTOOL=	YES
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
PKGCONFIG_OVERRIDE=	base/aiksaurus-1.0.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
