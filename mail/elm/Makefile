# $NetBSD: Makefile,v 1.25 2003/04/23 14:36:36 jschauma Exp $

DISTNAME=		elm2.5.5
PKGREVISION=		1
PKGNAME=		elm-2.5.5
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.virginia.edu/pub/elm/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.instinct.org/elm/
COMMENT=		ELM Mail User Agent (without ME extensions)

CONFLICTS+=		mm-[0-9]*
CONFLICTS+=		elm-me-[0-9]*

DEPENDS+=		metamail>=2.7:../../mail/metamail

USE_BUILDLINK2=		YES
HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-d

pre-configure:
	${CP} ${FILESDIR}/config.sh ${WRKSRC}/config.sh.orig
	${SED} -e 's:PREFIX:'${PREFIX}':g' \
		${WRKSRC}/config.sh.orig > ${WRKSRC}/config.sh.tmp
	${SED} -e 's:LOCALBASE:'${LOCALBASE}':g' \
		${WRKSRC}/config.sh.tmp > ${WRKSRC}/config.sh.tmp2
	${SED} -e 's:@CC@:'${BUILDLINK_CC}':g' \
		${WRKSRC}/config.sh.tmp2 > ${WRKSRC}/config.sh
	${MV} ${WRKSRC}/nls/LANGS ${WRKSRC}/nls/LANGS.tmpl
	${SED} -e 's:__PREFIX:'${PREFIX}':g' < ${WRKSRC}/nls/LANGS.tmpl > ${WRKSRC}/nls/LANGS

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
