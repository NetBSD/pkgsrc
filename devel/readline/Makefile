# $NetBSD: Makefile,v 1.14 2000/06/01 11:23:24 rh Exp $
#

DISTNAME=	readline-4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/readline/

GNU_CONFIGURE=	yes
USE_PKGLIBTOOL=	yes
USE_GTEXINFO=	yes
MAKE_ENV+=	READLINE_MAJOR=4 READLINE_MINOR=0

ALL_TARGET=	all documentation

.include "../../mk/bsd.pkg.mk"
