# $NetBSD: Makefile,v 1.19 2020/01/26 17:32:07 rillig Exp $

DISTNAME=	spiped-1.5.0
PKGREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	http://www.tarsnap.com/spiped/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tarsnap.com/spiped/
COMMENT=	Tool for creating symmetrically encrypted and authenticated pipes
LICENSE=	2-clause-bsd
USE_LANGUAGES=	c99

MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin
MAKE_FLAGS+=	MAN1DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

LDADD_EXTRA=	${COMPILER_RPATH_FLAG:Q}${BUILDLINK_PREFIX.openssl}/lib
LDADD_EXTRA+=	-L${BUILDLINK_PREFIX.openssl}/lib

OPSYSVARS+=		LDADD_EXTRA
LDADD_EXTRA.SunOS+=	-lsocket -lnsl

CFLAGS.SunOS+=	-D__EXTENSIONS__

SMF_METHODS=	spiped

MAKE_ENV+=	LDADD_EXTRA="${LDADD_EXTRA}"

INSTALLATION_DIRS+=	share/doc/spiped ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/spiped

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
