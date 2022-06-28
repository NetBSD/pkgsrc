# $NetBSD: Makefile,v 1.39 2022/06/28 11:34:09 wiz Exp $

DISTNAME=		cim-3.30
PKGREVISION=		11
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=cim/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/cim/cim.html
COMMENT=		Simula compiler based on the C programming language

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	libtool_path=${PKG_LIBTOOL:Q}
USE_TOOLS+=	perl:run
USE_LIBTOOL=	YES
INFO_FILES=	yes

.include "../../mk/bsd.pkg.mk"
