# $NetBSD: Makefile,v 1.30 2023/12/30 12:19:32 zafer Exp $
#

DISTNAME=	chipmunk-1.4
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	https://www.aydogan.net/distfiles/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.bitwizard.nl/chipmunk/index.html
COMMENT=	Shell-like tool for hardware debugging

BUILD_TARGET=	chipmunk
MAKE_ENV+=	CONFIG_OPTIONS=${CPPFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
MAKE_ENV+=	EXTRA_LIBS=-l${MACHINE_ARCH}
.  endif
.endif

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chipmunk ${DESTDIR}${PREFIX}/sbin/chipmunk

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
