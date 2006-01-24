# $NetBSD: Makefile,v 1.38 2006/01/24 22:47:13 joerg Exp $

DISTNAME=		elm2.5.8
PKGNAME=		elm-2.5.8
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.virginia.edu/pub/elm/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.instinct.org/elm/
COMMENT=		ELM Mail User Agent (without ME extensions)

DEPENDS+=		metamail>=2.7:../../mail/metamail

CONFLICTS+=		mm-[0-9]*
CONFLICTS+=		elm-me-[0-9]*

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-d
USE_TOOLS=		nroff

.include "../../mk/bsd.prefs.mk"

pre-configure:
	${CP} ${FILESDIR}/config.sh ${WRKSRC}/config.sh.orig
	${SED} -e 's:PREFIX:${PREFIX}:g' \
	  -e 's:LOCALBASE:${LOCALBASE}:g' \
	  -e 's:LIBC:${LIBC}:g' \
	  ${WRKSRC}/config.sh.orig > ${WRKSRC}/config.sh
	${MV} ${WRKSRC}/nls/LANGS ${WRKSRC}/nls/LANGS.tmpl
	${SED} -e 's:__PREFIX:'${PREFIX}':g' < ${WRKSRC}/nls/LANGS.tmpl > ${WRKSRC}/nls/LANGS

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
