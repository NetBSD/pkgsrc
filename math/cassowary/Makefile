# $NetBSD: Makefile,v 1.26 2004/10/03 00:12:55 tv Exp $
#

DISTNAME=		cassowary-0.60
PKGREVISION=		5
CATEGORIES=		math
MASTER_SITES=		http://www.cs.washington.edu/research/constraints/cassowary/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cs.washington.edu/research/constraints/cassowary/
COMMENT=		Constraint-solving toolkit for linear equalities and inequalities

BUILD_DEPENDS+=		bison>=1.34:../../devel/bison

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-fd-solver
CONFIGURE_ARGS+=	--with-gtl=${BUILDLINK_PREFIX.gtl}

PLIST_SUBST+=		GUILE14_SUBDIR=${GUILE14_SUBDIR}

YACC=			bison -y

UNLIMIT_RESOURCES=	datasize memorysize

.include "../../mk/bsd.prefs.mk"

post-install:
	cd ${PREFIX}/lib/cassowary && ${RMDIR} -p bench

.include "../../devel/gtl/buildlink3.mk"
.include "../../lang/guile14/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
