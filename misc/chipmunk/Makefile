# $NetBSD: Makefile,v 1.4 2001/02/17 18:08:53 wiz Exp $
#

DISTNAME=       chipmunk-1.4
CATEGORIES=	misc
MASTER_SITES=   http://www.bitwizard.nl/chipmunk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/chipmunk/index.html
COMMENT=	shell-like tool for hardware debugging

.if exists(/usr/include/readline.h)
CPPFLAGS+=	-DHAVE_READLINE_H=1
LIBREADLINE=	edit
.else
DEPENDS+=	readline>=4.0:../../devel/readline
CPPFLAGS+=	-I${LOCALBASE}/include
LIBREADLINE=	readline
.endif

ONLY_FOR_PLATFORM=	NetBSD-*-i386

ALL_TARGET=	chipmunk
MAKE_ENV+=	CONFIG_OPTIONS="${CPPFLAGS}" EXTRA_LIBS=-li386 \
		LIBREADLINE=${LIBREADLINE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chipmunk ${PREFIX}/sbin/chipmunk

.include "../../mk/bsd.pkg.mk"
