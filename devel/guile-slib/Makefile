# $NetBSD: Makefile,v 1.36 2008/01/12 19:13:07 gdt Exp $

DISTNAME=	guile-slib-3.1.5
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB glue files for guile 1.8

# This does not quite work.  The problem is that new-catalog writes
# the catalog in /usr/pkg/share/guile/site, rarther than the proper
# place in the destdir.
#PKG_DESTDIR_SUPPORT=	user-destdir

# tested with 3.1.5
DEPENDS+=	slib>=3.1.2nb1:../../devel/slib

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	share/guile share/guile/site

do-install:
	${LN} -sf ${PREFIX}/share/slib \
		${DESTDIR}${PREFIX}/share/guile/site/slib
	${RM} -f ${DESTDIR}${PREFIX}/share/guile/slibcat
	cd ${DESTDIR}${PREFIX}/share/guile/site/slib && \
		GUILE_LOAD_PATH=${PREFIX}/share \
		guile -q -c "(begin (use-modules (ice-9 slib)) (require 'new-catalog))"

# Our 1.8.2 package applies a necessary patch.
BUILDLINK_API_DEPENDS.guile+=	guile>=1.8.2
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
