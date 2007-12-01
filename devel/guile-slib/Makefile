# $NetBSD: Makefile,v 1.35 2007/12/01 15:56:25 gdt Exp $

DISTNAME=	guile-slib-3.1.5
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB glue files for guile 1.8

# tested with 3.1.5
DEPENDS+=	slib>=3.1.2nb1:../../devel/slib

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	share/guile

do-install:
	${LN} -sf ${PREFIX}/share/slib ${PREFIX}/share/guile/site/slib
	${RM} -f ${PREFIX}/share/guile/slibcat
	cd ${PREFIX}/share/guile/site/slib; \
		guile -q -c "(begin (use-modules (ice-9 slib)) (require 'new-catalog))"

# Our 1.8.2 package applies a necessary patch.
BUILDLINK_API_DEPENDS.guile+=	guile>=1.8.2
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
