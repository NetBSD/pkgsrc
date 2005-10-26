# $NetBSD: Makefile,v 1.29 2005/10/26 13:03:08 gdt Exp $

DISTNAME=	guile-slib-3.1.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB glue files for guile 1.6

DEPENDS+=	slib>=3.1.2:../../devel/slib

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	share/guile

do-install:
	${LN} -sf ${PREFIX}/share/slib ${PREFIX}/share/guile/slib
	${RM} -f ${PREFIX}/share/guile/slibcat
	cd ${PREFIX}/share/guile/slib; \
		guile -q -l guile.init -c \
			"(require 'new-catalog)"

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
