# $NetBSD: Makefile,v 1.3 2001/02/19 21:44:00 jtb Exp $

DISTNAME=		rs-0.7.3.1
PKGNAME=		RScheme-0.7.3.1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.rscheme.org/pub/rscheme/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.rscheme.org
COMMENT=		Scheme implementation

WRKSRC=			${WRKDIR}/${DISTNAME}/src
HAS_CONFIGURE=		#defined
CONFIGURE_ARGS+=	"--prefix=${PREFIX}/lib/RScheme"
ALL_TARGET=		base

pre-configure:
	cd ${WRKDIR}/${DISTNAME} && ${MAKE} stage1

do-install:
	cd ${WRKSRC} && ${MAKE} install-base && ${MAKE} shell && \
	${MAKE} install-shell && ${MAKE} packages

post-install:
	${LN} -fs ${PREFIX}/lib/RScheme/bin/rs ${PREFIX}/bin/RScheme
	${LN} -fs ${PREFIX}/lib/RScheme/bin/rs ${PREFIX}/bin/rscheme
	${LN} -fs ${PREFIX}/lib/RScheme/bin/rsc ${PREFIX}/bin/RSchemec
	${LN} -fs ${PREFIX}/lib/RScheme/bin/rsc ${PREFIX}/bin/rschemec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/RScheme
	${INSTALL_DATA} ${WRKSRC}/../COPYING ${WRKSRC}/../README \
	${PREFIX}/share/doc/RScheme

.include "../../mk/bsd.pkg.mk"
