# $NetBSD: Makefile,v 1.15 2015/01/04 03:07:51 dholland Exp $
#

DISTNAME=	veleng10
PKGNAME=	velena-1.0
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.ce.unipr.it/~gbe/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ce.unipr.it/~gbe/
COMMENT=	Perfect-play engine for connect four
LICENSE=	velena-license

RESTRICTED=		You must not charge a fee for this software nor for any derived work in which this software is included.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

# These platforms cannot build 32-on-64 binaries.
NOT_FOR_PLATFORM+=	*-*-alpha
NOT_FOR_PLATFORM+=	DragonFly-*-x86_64

EXTRACT_OPTS_ZIP=	-LLaqo
WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
AUTO_MKDIRS=		yes

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	connect4.h
SUBST_SED.path=		-e 's,"white_ob.cn4","${PREFIX}/share/velena/white_ob.cn4",'

SUBST_CLASSES+=		ansi-c
SUBST_STAGE.ansi-c=	pre-configure
SUBST_FILES.ansi-c=	*.c *.h
SUBST_SED.ansi-c=	-e 's,<malloc\.h>,<stdlib.h>,'

SUBST_CLASSES+=		cflags
SUBST_STAGE.cflags=	pre-configure
SUBST_FILES.cflags=	makefile
SUBST_SED.cflags=	-e s,^CFLAGS.*,,

.include "../../mk/bsd.prefs.mk"

# Velena isn't 64bit-safe, which results in a "fatal error" for some
# board positions.
#
# Try for example "c170", which works with -m32 and fails without.
#
.for P in ${LP64PLATFORMS}
.if ${MACHINE_PLATFORM:M${P}}
CFLAGS+=		-m32
LDFLAGS+=		-m32
.endif
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/veleng ${DESTDIR}${PREFIX}/bin/velena
	${INSTALL_DATA} ${WRKSRC}/readme ${DESTDIR}${PREFIX}/share/doc/velena/README
	${INSTALL_DATA} ${WRKSRC}/white_ob.cn4 ${DESTDIR}${PREFIX}/share/velena/.

.include "../../mk/bsd.pkg.mk"
