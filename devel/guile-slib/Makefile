# $NetBSD: Makefile,v 1.42 2010/03/24 19:43:23 asau Exp $

DISTNAME=	guile-slib-3.2.2
PKGREVISION=	2
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

DEPENDS+=	slib>=3.2.2:../../devel/slib

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
