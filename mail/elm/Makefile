# $NetBSD: Makefile,v 1.6 1998/04/20 11:56:25 frueauf Exp $
# FreeBSD: Makefile,v 1.42 1997/12/24 01:21:07 alex Exp
#

DISTNAME=		elm-2.4ME+32
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.ozone.fmi.fi/KEH/ \
			ftp://ftp.funet.fi/pub/unix/mail/elm/elm-2.4ME+/ \
			ftp://ftp.ibp.fr/pub/unix/mail/elm-me/

MAINTAINER=		packages@netbsd.org

WRKSRC=			${WRKDIR}/elm2.4.ME+.32
MAN1=			answer.1 checkalias.1 elm.1 elmalias.1 fastmail.1 \
			frm.1 listalias.1 messages.1 newalias.1 newmail.1 \
			printmail.1 readmsg.1 wnewmail.1
CAT1=			answer.0 checkalias.0 elm.0 elmalias.0 fastmail.0 \
			frm.0 listalias.0 messages.0 newalias.0 newmail.0 \
			printmail.0 readmsg.0 wnewmail.0

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
