# $NetBSD: Makefile,v 1.35 2019/11/03 19:03:56 rillig Exp $

DISTNAME=		cim-3.30
PKGREVISION=		8
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=cim/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/cim/cim.html
COMMENT=		Simula compiler based on the C programming language

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	libtool_path=${PKG_LIBTOOL:Q}
USE_TOOLS+=	perl:run
USE_LIBTOOL=	YES
INFO_FILES=	yes

.include "../../mk/bsd.pkg.mk"
