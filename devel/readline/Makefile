# $NetBSD: Makefile,v 1.23 2003/06/02 01:20:15 jschauma Exp $
#

DISTNAME=	readline-4.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/readline/
COMMENT=	GNU library that can recall and edit previous input

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

ALL_TARGET=		all-la
INSTALL_TARGET=		install-la

INFO_FILES=		readline.info history.info rluserman.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
