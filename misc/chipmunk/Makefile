# $NetBSD: Makefile,v 1.6 2001/05/24 08:53:57 jlam Exp $
#

DISTNAME=       chipmunk-1.4
CATEGORIES=	misc
MASTER_SITES=   http://www.bitwizard.nl/chipmunk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/chipmunk/index.html
COMMENT=	shell-like tool for hardware debugging

ONLY_FOR_PLATFORM=	NetBSD-*-i386

.include "../../devel/readline/buildlink.mk"

ALL_TARGET=	chipmunk
MAKE_ENV+=	CONFIG_OPTIONS="${CPPFLAGS}"
MAKE_ENV+=	EXTRA_LIBS=-li386

CPPFLAGS+=	-I${BUILDLINK_INCDIR}
LDFLAGS+=	-L${BUILDLINK_LIBDIR}

pre-configure: ${BUILDLINK_TARGETS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chipmunk ${PREFIX}/sbin/chipmunk

.include "../../mk/bsd.pkg.mk"
