# $NetBSD: Makefile,v 1.13 2003/01/07 03:56:26 uebayasi Exp $
#

DISTNAME=		cassowary-0.60
CATEGORIES=		math
MASTER_SITES=		http://www.cs.washington.edu/research/constraints/cassowary/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.washington.edu/research/constraints/cassowary/
COMMENT=		Constraint-solving toolkit for linear equalities and inequalities

BUILD_DEPENDS+=		bison>=1.34:../../devel/bison
DEPENDS+=		gtl>=0.3.2:../../devel/gtl

USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-fd-solver
CONFIGURE_ARGS+=	--with-guile-prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--with-gtl=${LOCALBASE}

YACC=			bison -y

UNLIMIT_RESOURCES=	datasize memorysize

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=		egcs-1.1.2:../../lang/egcs
MAKE_ENV+=		CXX=${LOCALBASE}/egcs/bin/g++
.endif

post-install:
	cd ${PREFIX}/lib/cassowary && ${RMDIR} -p bench

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
