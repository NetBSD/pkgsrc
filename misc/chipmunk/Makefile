# $NetBSD: Makefile,v 1.15 2004/10/03 00:12:58 tv Exp $
#

DISTNAME=       chipmunk-1.4
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=   http://www.bitwizard.nl/chipmunk/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/chipmunk/index.html
COMMENT=	Shell-like tool for hardware debugging

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_BUILDLINK3=		# defined

ALL_TARGET=	chipmunk
MAKE_ENV+=	CONFIG_OPTIONS="${CPPFLAGS}"
MAKE_ENV+=	EXTRA_LIBS=-li386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chipmunk ${PREFIX}/sbin/chipmunk

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
