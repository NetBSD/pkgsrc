# $NetBSD: Makefile,v 1.22 2004/01/24 13:58:23 grant Exp $
#

DISTNAME=		cassowary-0.60
PKGREVISION=		4
CATEGORIES=		math
MASTER_SITES=		http://www.cs.washington.edu/research/constraints/cassowary/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cs.washington.edu/research/constraints/cassowary/
COMMENT=		Constraint-solving toolkit for linear equalities and inequalities

BUILD_DEPENDS+=		bison>=1.34:../../devel/bison

USE_BUILDLINK2=		# defined
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-fd-solver
CONFIGURE_ARGS+=	--with-gtl=${BUILDLINK_PREFIX.gtl}

PLIST_SUBST+=		GUILE14_SUBDIR=${GUILE14_SUBDIR}

YACC=			bison -y

UNLIMIT_RESOURCES=	datasize memorysize

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=		egcs-1.1.2:../../lang/egcs
MAKE_ENV+=		CXX=${LOCALBASE}/egcs/bin/g++
.endif

post-install:
	cd ${PREFIX}/lib/cassowary && ${RMDIR} -p bench

.include "../../devel/gtl/buildlink2.mk"
.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
