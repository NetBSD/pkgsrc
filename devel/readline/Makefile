# $NetBSD: Makefile,v 1.15 2000/06/09 07:06:34 jlam Exp $
#

DISTNAME=	readline-4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/readline/

GNU_CONFIGURE=	# defined
USE_LIBTOOL=	# defined
USE_GTEXINFO=	# defined
MAKE_ENV+=	READLINE_MAJOR=4 READLINE_MINOR=0

ALL_TARGET=	all documentation

.include "../../mk/bsd.pkg.mk"
