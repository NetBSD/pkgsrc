# $NetBSD: Makefile,v 1.2 2006/10/16 12:01:49 obache Exp $
#

DISTNAME=		makedepf90-2.8.8
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
