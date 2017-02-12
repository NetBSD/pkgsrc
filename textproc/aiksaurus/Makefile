# $NetBSD: Makefile,v 1.21 2017/02/12 06:26:04 ryoon Exp $
#

DISTNAME=	aiksaurus-1.2.1
PKGREVISION=	4
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
