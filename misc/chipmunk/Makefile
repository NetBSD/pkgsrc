# $NetBSD: Makefile,v 1.11 2003/06/02 01:18:18 jschauma Exp $
#

DISTNAME=       chipmunk-1.4
CATEGORIES=	misc
MASTER_SITES=   http://www.bitwizard.nl/chipmunk/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/chipmunk/index.html
COMMENT=	shell-like tool for hardware debugging

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_BUILDLINK2=		# defined

ALL_TARGET=	chipmunk
MAKE_ENV+=	CONFIG_OPTIONS="${CPPFLAGS}"
MAKE_ENV+=	EXTRA_LIBS=-li386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chipmunk ${PREFIX}/sbin/chipmunk

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
