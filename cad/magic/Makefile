# $NetBSD: Makefile,v 1.1.1.1 2002/04/06 21:37:28 dmcmahill Exp $
#

DISTNAME=	magic-7.1
CATEGORIES=	cad
MASTER_SITES=	http://vlsi.cornell.edu/magic/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://vlsi.cornell.edu/magic/
COMMENT=	Integrated circuit layout system

USE_GMAKE=	yes
MAKE_ENV+=	CAD_HOME=${PREFIX}

do-configure:
	cd ${WRKSRC} && printf "1\n2\n6\n\n\n\n\n\n\n\n\n\n\n" | \
		${ENV} ${MAKE_ENV} ./scripts/config

.include "../../mk/bsd.pkg.mk"
