# $NetBSD: Makefile,v 1.5 2000/06/01 11:23:34 rh Exp $
#

DISTNAME=		cassowary-0.50
CATEGORIES=		math
MASTER_SITES=		http://www.cs.washington.edu/research/constraints/cassowary/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.washington.edu/research/constraints/cassowary/

DEPENDS+=		guile-1.3.*:../../lang/guile
BUILD_DEPENDS+=		${LOCALBASE}/bin/bison:../../devel/bison

GNU_CONFIGURE=		yes
USE_PKGLIBTOOL=		yes
USE_GMAKE=		yes

YACC=			${LOCALBASE}/bin/bison -y
CONFIGURE_ARGS+=	--with-guile-prefix=${LOCALBASE}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=		egcs-1.1.2:../../lang/egcs
MAKE_ENV+=		CXX=${LOCALBASE}/egcs/bin/g++
.endif

.include "../../mk/bsd.pkg.mk"
