# $NetBSD: Makefile,v 1.26 2003/07/17 21:33:35 grant Exp $
#

DISTNAME=	readline-4.3
PKGNAME=	${DISTNAME}pl5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

PATCH_SITES=	${MASTER_SITES:=${DISTNAME}-patches/}
PATCHFILES=	readline43-001 readline43-002 readline43-003 readline43-004 \
		readline43-005

MAINTAINER=	tech-pkg@NetBSD.org
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
