# $NetBSD: Makefile,v 1.6 2001/02/16 14:38:22 wiz Exp $
#

DISTNAME=		diffutils-2.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=diffutils/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/diffutils/diffutils.html
COMMENT=		GNU diff utilities - find the differences between files

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-prefix=g
INFO_FILES=		diff.info

.include "../../mk/bsd.pkg.mk"
