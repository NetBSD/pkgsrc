# $NetBSD: Makefile,v 1.20 2003/07/13 13:52:29 wiz Exp $
#

DISTNAME=		cassowary-0.60
PKGREVISION=		4
CATEGORIES=		math
MASTER_SITES=		http://www.cs.washington.edu/research/constraints/cassowary/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.cs.washington.edu/research/constraints/cassowary/
COMMENT=		Constraint-solving toolkit for linear equalities and inequalities

BUILD_DEPENDS+=		bison>=1.34:../../devel/bison

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined
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
