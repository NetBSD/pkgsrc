# $NetBSD: Makefile,v 1.30 2004/04/21 04:58:19 snj Exp $

DISTNAME=		elm2.5.5
PKGREVISION=		2
PKGNAME=		elm-2.5.5
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.virginia.edu/pub/elm/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.instinct.org/elm/
COMMENT=		ELM Mail User Agent (without ME extensions)

CONFLICTS+=		mm-[0-9]*
CONFLICTS+=		elm-me-[0-9]*

DEPENDS+=		metamail>=2.7:../../mail/metamail

USE_BUILDLINK3=		YES
HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-d

pre-configure:
	${CP} ${FILESDIR}/config.sh ${WRKSRC}/config.sh.orig
	${SED} -e 's:PREFIX:'${PREFIX}':g' \
		${WRKSRC}/config.sh.orig > ${WRKSRC}/config.sh.tmp
	${SED} -e 's:LOCALBASE:'${LOCALBASE}':g' \
		${WRKSRC}/config.sh.tmp > ${WRKSRC}/config.sh.tmp2
	${SED} -e 's:@CC@:'${CC}':g' \
		${WRKSRC}/config.sh.tmp2 > ${WRKSRC}/config.sh
	${MV} ${WRKSRC}/nls/LANGS ${WRKSRC}/nls/LANGS.tmpl
	${SED} -e 's:__PREFIX:'${PREFIX}':g' < ${WRKSRC}/nls/LANGS.tmpl > ${WRKSRC}/nls/LANGS

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
