# $NetBSD: Makefile,v 1.5 2001/01/13 16:17:48 tron Exp $
#

DISTNAME=		diffutils-2.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=diffutils/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/diffutils/diffutils.html

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-prefix=g
INFO_FILES=		diff.info

.include "../../mk/bsd.pkg.mk"
