# $NetBSD: Makefile,v 1.30 2004/03/23 04:41:00 jlam Exp $
#

DISTNAME=	readline-4.3
PKGNAME=	${DISTNAME}pl5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

PATCH_SITES=	${MASTER_SITES:=${DISTNAME}-patches/}
PATCHFILES=	readline43-001 readline43-002 readline43-003 readline43-004 \
		readline43-005

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cnswww.cns.cwru.edu/php/chet/readline/rltop.html
COMMENT=	GNU library that can recall and edit previous input

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

ALL_TARGET=		all-la
INSTALL_TARGET=		install-la

INFO_FILES=		readline.info history.info rluserman.info

.include "../../mk/bsd.pkg.mk"
