# $NetBSD: Makefile,v 1.1.1.1 2000/11/30 04:56:21 jtb Exp $

DISTNAME=		rs-0.7.3.1
PKGNAME=		RScheme-0.7.3.1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.rscheme.org/pub/rscheme/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.rscheme.org

WRKSRC=			${WRKDIR}/${DISTNAME}/src
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	"--prefix=${PREFIX}/lib/RScheme"
ALL_TARGET=		base

pre-configure:
	(cd ${WRKDIR}/${DISTNAME} && ${MAKE} stage1)

do-install:
	(cd ${WRKSRC} && ${MAKE} install-base && ${MAKE} shell && \
	${MAKE} install-shell && ${MAKE} packages)

post-install:
	@(cd ${PREFIX}/bin ;					\
	${LN} -sf ../lib/RScheme/bin/rs RScheme ; 		\
	${LN} -sf ../lib/RScheme/bin/rs rscheme ; 		\
	${LN} -sf ../lib/RScheme/bin/rsc RSchemec ;		\
	${LN} -sf ../lib/RScheme/bin/rsc rschemec )
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/RScheme
	${INSTALL_DATA} ${WRKSRC}/../COPYING ${WRKSRC}/../README \
	${PREFIX}/share/doc/RScheme

.include "../../mk/bsd.pkg.mk"
