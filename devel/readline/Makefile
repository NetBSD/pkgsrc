# $NetBSD: Makefile,v 1.20.2.1 2002/05/11 02:09:06 jlam Exp $
#

DISTNAME=	readline-4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/readline/
COMMENT=	GNU library that can recall and edit previous input

USE_BUILDLINK2_ONLY=	# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

ALL_TARGET=		all-la
INSTALL_TARGET=		install-la

INFO_FILES=		readline.info history.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
