# $NetBSD: Makefile,v 1.9 2002/04/11 02:01:43 dmcmahill Exp $

DISTNAME=		rs-0.7.3.1
PKGNAME=		RScheme-0.7.3.1
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.rscheme.org/pub/rscheme/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.rscheme.org
COMMENT=		Scheme implementation

HAS_CONFIGURE=		#defined
CONFIGURE_ARGS+=	--prefix=${PREFIX}/lib/RScheme
ALL_TARGET=		base

NOT_FOR_PLATFORM=       *-*-alpha

#
# Can't define WRKSRC as the src subdir since it doesn't appear until after
# the configure stage and patches need to be applied before then.
#
pre-configure:
	cd ${WRKSRC} && ${MAKE} stage1

do-configure:
	cd ${WRKSRC}/src && ./configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC}/src && ${MAKE} ${ALL_TARGET}

do-install:
	cd ${WRKSRC}/src && ${MAKE} install-base && ${MAKE} shell && \
	${MAKE} install-shell && ${MAKE} packages

post-install:
	${LN} -fs ${PREFIX}/lib/RScheme/bin/rs ${PREFIX}/bin/RScheme
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/RScheme
	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/README \
	${PREFIX}/share/doc/RScheme

.include "../../mk/bsd.pkg.mk"
