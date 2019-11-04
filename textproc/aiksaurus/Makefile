# $NetBSD: Makefile,v 1.28 2019/11/04 21:43:33 rillig Exp $
#

DISTNAME=	aiksaurus-1.2.1
PKGREVISION=	9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aiksaurus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aiksaurus.sourceforge.net/
COMMENT=	English-language thesaurus
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	base/aiksaurus-1.0.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
