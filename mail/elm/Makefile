# $NetBSD: Makefile,v 1.8 1998/08/20 15:17:09 tsarna Exp $
# FreeBSD: Makefile,v 1.42 1997/12/24 01:21:07 alex Exp
#

DISTNAME=		elm-2.4ME+32
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.ozone.fmi.fi/KEH/ \
			ftp://ftp.funet.fi/pub/unix/mail/elm/elm-2.4ME+/ \
			ftp://ftp.ibp.fr/pub/unix/mail/elm-me/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.myxa.com/elm/

WRKSRC=			${WRKDIR}/elm2.4.ME+.32

HAS_CONFIGURE=		Yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ENV=		PREFIX="${PREFIX}"
CONFIGURE_ARGS=		-S

pre-configure:
	${MV} ${WRKSRC}/nls/LANGS ${WRKSRC}/nls/LANGS.tmpl
	${SED} -e 's:__PREFIX:'${PREFIX}':g'< ${WRKSRC}/nls/LANGS.tmpl > ${WRKSRC}/nls/LANGS

post-install:
	cd ${WRKSRC}/nls; ${MAKE} install
	if [ -f ${PREFIX}/lib/elm.mimetypes ] ; then \
		${INSTALL_DATA} \
			${FILESDIR}/elm.mimetypes ${PREFIX}/lib/elm.mimetypes-dist; \
	else \
		${INSTALL_DATA} \
			${FILESDIR}/elm.mimetypes ${PREFIX}/lib; \
	fi

.include "../../mk/bsd.pkg.mk"
