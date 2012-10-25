# $NetBSD: Makefile,v 1.10 2012/10/25 06:55:45 asau Exp $
#
# In order to ensure compliance with U.S. and international law, please
# do not modify this file to provide pointers to the source or homepage
# for this software or submit any PRs telling us the contents of the
# HOMEPAGE or MASTER_SITES definitions in this Makefile.

DISTNAME=		clit18src
PKGNAME=		convertlit-1.8
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${CONVERTLIT_MASTER_SITES}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${CONVERTLIT_HOMEPAGE}
COMMENT=		Convert Microsoft Legal Reader format eBooks into open format

WRKSRC=			${WRKDIR}
BUILD_DIRS=		lib clit18
MAKE_FILE=		Makefile
USE_TOOLS+=		gmake

SUBST_CLASSES+=		d2u
SUBST_STAGE.d2u=	pre-configure
SUBST_MESSAGE.d2u=	Stripping CRLF line ends.
SUBST_FILES.d2u+=		*.h *.c */*.h */*.c */*/*.h */*/*.c
SUBST_FILTER_CMD.d2u=	${TR} -d '\r'

SUBST_CLASSES+=		flags
SUBST_STAGE.flags=	pre-configure
SUBST_MESSAGE.flags=	Fixing CFLAGS and compiler invocation.
SUBST_FILES.flags+=		clit18/Makefile
SUBST_SED.flags+=	-e 's,^CFLAGS=.*,CFLAGS+=-funsigned-char -Wall -I ../lib -I ../lib/des -I .,'
SUBST_SED.flags+=	-e 's,gcc -o clit ..  ../libtommath-0.30/libtommath.a,gcc $$(LDFLAGS) -o clit $$^ -ltommath,'

RESTRICTED=		Possible legal problems
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clit18/clit ${DESTDIR}${PREFIX}/bin/convertlit

.include "../../math/ltm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
