# $NetBSD: Makefile,v 1.21 2006/03/04 21:30:10 jlam Exp $
#

DISTNAME=       chipmunk-1.4
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=   http://www.bitwizard.nl/chipmunk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/chipmunk/index.html
COMMENT=	Shell-like tool for hardware debugging

ONLY_FOR_PLATFORM=	NetBSD-*-i386


BUILD_TARGET=	chipmunk
MAKE_ENV+=	CONFIG_OPTIONS=${CPPFLAGS:M*:Q}
MAKE_ENV+=	EXTRA_LIBS=-li386

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chipmunk ${PREFIX}/sbin/chipmunk

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
