# $NetBSD: Makefile,v 1.21 2002/05/26 10:42:39 wiz Exp $

DISTNAME=		elm2.5.5
PKGNAME=		elm-2.5.5
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.virginia.edu/pub/elm/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.instinct.org/elm/
COMMENT=		ELM Mail User Agent (without ME extensions)

CONFLICTS+=		mm-[0-9]* metamail-[0-9]*
CONFLICTS+=		elm-me-[0-9]*

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

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
