# $NetBSD: Makefile,v 1.42 2022/06/28 11:34:20 wiz Exp $

DISTNAME=		elm-2.4ME+93
PKGNAME=		elm-me-2.4.93
PKGREVISION=		8
CATEGORIES=		mail
MASTER_SITES=		http://ftp.funet.fi/pub/unix/mail/elm/elm-2.4ME+/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.instinct.org/elm/
COMMENT=		ELM Mail User Agent with ME extensions

MAKE_JOBS_SAFE=		no

CONFLICTS=		elm-[0-9]*

WRKSRC=			${WRKDIR}/elm2.4.ME+.93
HAS_CONFIGURE=		YES
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q} RUN_AS_BATCH=yes
CONFIG_SHELL=		ksh
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-S

INSTALL_DIRS=		. nls
INSTALLATION_DIRS=	share/nls/C

CONF_FILES=		${PREFIX}/lib/elm.mimetypes-dist		\
			${PREFIX}/lib/elm.mimetypes

USE_TOOLS+=		ksh

SUBST_CLASSES+=		errno
SUBST_STAGE.errno=	pre-configure
SUBST_MESSAGE.errno=	Fixing declaration of errno.
SUBST_FILES.errno=	*/*.c
SUBST_SED.errno=	-e 's,^extern int errno;,\#include <errno.h>,'

# occurs in elmlib.h and is properly protected code:
#  #define hex(c) ((((c) > 0) && ((c) < 127)) ? index_hex[ (c) ] : -1)
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

# currently not set in files/config.sh
# (should probably be a package option)
#SPECIAL_PERMS+=	bin/elm ${ROOT_USER} mail 2755

pre-configure:
	${CP} ${FILESDIR}/config.sh ${WRKSRC}/
	${MV} ${WRKSRC}/nls/LANGS ${WRKSRC}/nls/LANGS.tmpl
	${SED} -e 's:__PREFIX:'${PREFIX}':g'< ${WRKSRC}/nls/LANGS.tmpl > ${WRKSRC}/nls/LANGS

post-install:
	${INSTALL_DATA} ${FILESDIR}/elm.mimetypes			\
		${DESTDIR}${PREFIX}/lib/elm.mimetypes-dist

post-configure:
	${TOUCH} ${WRKSRC}/config.sh
	${TOUCH} ${WRKSRC}/config.h
	${TOUCH} ${WRKSRC}/Makefile
	${TOUCH} ${WRKSRC}/*/Makefile

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
