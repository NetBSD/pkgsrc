# $NetBSD: Makefile,v 1.17 2001/02/16 14:39:00 wiz Exp $
#

DISTNAME=	readline-4.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/readline/
COMMENT=	GNU library which can recall and edit previous input

GNU_CONFIGURE=	# defined
USE_LIBTOOL=	# defined
USE_GTEXINFO=	# defined

READLINE_MAJOR=	4
READLINE_MINOR=	1

MAKE_ENV+=	READLINE_MAJOR=${READLINE_MAJOR}
MAKE_ENV+=	READLINE_MINOR=${READLINE_MINOR}

PLIST_SUBST+=	READLINE_MAJOR=${READLINE_MAJOR}
PLIST_SUBST+=	READLINE_MINOR=${READLINE_MINOR}

ALL_TARGET=	all documentation
INFO_FILES=	readline.info history.info

.include "../../mk/bsd.pkg.mk"
