# $NetBSD: Makefile,v 1.28 2007/12/02 12:12:47 wiz Exp $

DISTNAME=		elm-2.4ME+93
PKGNAME=		elm-me-2.4.93
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.funet.fi/pub/unix/mail/elm/elm-2.4ME+/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.instinct.org/elm/
COMMENT=		ELM Mail User Agent with ME extensions

CONFLICTS=		elm-[0-9]*

WRKSRC=			${WRKDIR}/elm2.4.ME+.93
HAS_CONFIGURE=		YES
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q} RUN_AS_BATCH=yes
CONFIG_SHELL=		ksh
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-S

INSTALL_DIRS=		${WRKSRC} ${WRKSRC}/nls
INSTALLATION_DIRS=	share/nls/C

CONF_FILES=		${PREFIX}/lib/elm.mimetypes-dist		\
			${PREFIX}/lib/elm.mimetypes

USE_TOOLS+=	ksh

pre-configure:
	${CP} ${FILESDIR}/config.sh ${WRKSRC}/
	${MV} ${WRKSRC}/nls/LANGS ${WRKSRC}/nls/LANGS.tmpl
	${SED} -e 's:__PREFIX:'${PREFIX}':g'< ${WRKSRC}/nls/LANGS.tmpl > ${WRKSRC}/nls/LANGS

post-install:
	${INSTALL_DATA} ${FILESDIR}/elm.mimetypes			\
		${PREFIX}/lib/elm.mimetypes-dist

post-configure:
	${TOUCH} ${WRKSRC}/config.sh
	${TOUCH} ${WRKSRC}/config.h
	${TOUCH} ${WRKSRC}/Makefile
	${TOUCH} ${WRKSRC}/*/Makefile

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
