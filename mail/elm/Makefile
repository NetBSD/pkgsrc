# $NetBSD: Makefile,v 1.16 2001/07/18 20:04:11 martin Exp $
#

DISTNAME=		elm2.5.5
PKGNAME=		elm-2.5.5
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.virginia.edu/pub/elm/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.instinct.org/elm/
COMMENT=		ELM Mail User Agent (without ME extensions)

CONFLICTS=		elm-*

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-d

pre-configure:
	${CP} ${FILESDIR}/config.sh ${WRKSRC}/config.sh.orig
	${SED} -e 's:PREFIX:'${PREFIX}':g' \
		${WRKSRC}/config.sh.orig > ${WRKSRC}/config.sh.tmp
	${SED} -e 's:LOCALBASE:'${LOCALBASE}':g' \
		${WRKSRC}/config.sh.tmp > ${WRKSRC}/config.sh
	${MV} ${WRKSRC}/nls/LANGS ${WRKSRC}/nls/LANGS.tmpl
	${SED} -e 's:__PREFIX:'${PREFIX}':g' < ${WRKSRC}/nls/LANGS.tmpl > ${WRKSRC}/nls/LANGS

.include "../../mk/bsd.pkg.mk"
