# $NetBSD: Makefile,v 1.1.1.1 2006/04/13 16:40:59 minskim Exp $
#

DISTNAME=		makedepf90-2.8.4
CATEGORIES=		devel
MASTER_SITES=		http://www.helsinki.fi/~eedelman/makedepf90/

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://www.helsinki.fi/~eedelman/makedepf90/
COMMENT=		Creates Makefile dependencies for Fortran code

USE_TOOLS+=		lex yacc

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-build:
	cd ${WRKSRC:Q} && make


.include "../../mk/bsd.pkg.mk"
