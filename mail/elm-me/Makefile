# $NetBSD: Makefile,v 1.15 2004/10/03 00:12:52 tv Exp $
# FreeBSD: Makefile,v 1.42 1997/12/24 01:21:07 alex Exp
#

DISTNAME=		elm-2.4ME+93
PKGNAME=		elm-me-2.4.93
PKGREVISION=				2
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.ozone.fmi.fi/KEH/ \
			ftp://ftp.funet.fi/pub/unix/mail/elm/elm-2.4ME+/ \
			ftp://ftp.ibp.fr/pub/unix/mail/elm-me/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.instinct.org/elm/
COMMENT=		ELM Mail User Agent with ME extensions

CONFLICTS=		elm-[0-9]*

WRKSRC=			${WRKDIR}/elm2.4.ME+.93
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	ksh ./Configure
CONFIGURE_ENV=		PREFIX="${PREFIX}" RUN_AS_BATCH=yes
CONFIGURE_ARGS=		-S

INSTALL_DIRS=		${WRKSRC} ${WRKSRC}/nls

SUPPORT_FILES=		${PREFIX}/lib/elm.mimetypes-dist		\
			${PREFIX}/lib/elm.mimetypes

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
