# $NetBSD: Makefile,v 1.36 2023/01/03 17:38:18 wiz Exp $
#

DISTNAME=	aiksaurus-1.2.1
PKGREVISION=	14
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aiksaurus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aiksaurus.sourceforge.net/
COMMENT=	English-language thesaurus
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	base/aiksaurus-1.0.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
