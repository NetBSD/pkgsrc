# $NetBSD: Makefile,v 1.24 2003/06/25 11:32:38 seb Exp $
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

USE_NEW_TEXINFO=	YES
INFO_FILES=		readline.info history.info rluserman.info

.include "../../mk/bsd.pkg.mk"
