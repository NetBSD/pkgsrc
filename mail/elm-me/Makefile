# $NetBSD: Makefile,v 1.6 2002/10/23 00:07:07 jlam Exp $
# FreeBSD: Makefile,v 1.42 1997/12/24 01:21:07 alex Exp
#

DISTNAME=		elm-2.4ME+93
PKGNAME=		elm-me-2.4.93
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.ozone.fmi.fi/KEH/ \
			ftp://ftp.funet.fi/pub/unix/mail/elm/elm-2.4ME+/ \
			ftp://ftp.ibp.fr/pub/unix/mail/elm-me/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.instinct.org/elm/
COMMENT=		ELM Mail User Agent with ME extensions

CONFLICTS=		elm-[0-9]*

USE_BUILDLINK2=		YES
HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	ksh ./Configure
CONFIGURE_ENV=		PREFIX="${PREFIX}" RUN_AS_BATCH=yes
CONFIGURE_ARGS=		-S

WRKSRC=			${WRKDIR}/elm2.4.ME+.93
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

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
