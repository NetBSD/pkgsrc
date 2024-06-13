# $NetBSD: Makefile,v 1.3 2024/06/13 15:22:14 manu Exp $

GITHUB_PROJECT=	srs-milter
GITHUB_TAG=	3c44b13a10471df0361c08786c8826ea1d0ecc7b
DISTNAME=	3c44b13a10471df0361c08786c8826ea1d0ecc7b
PKGNAME=	${GITHUB_PROJECT}-20141121
PKGREVISION=	10
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=emsearcy/}
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/emsearcy/srs-milter
COMMENT=	Sender Rewriting Scheme milter
LICENSE=	generic-nonlicense

WRKSRC=	${WRKDIR}/srs-milter-3c44b13a10471df0361c08786c8826ea1d0ecc7b/src

LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	sbin

RCD_SCRIPTS=	srs-milter-in srs-milter-out

BUILD_DEFS+=	MILTER_USER VARBASE
FILES_SUBST+=	MILTER_USER=${MILTER_USER:Q}

do-build:
	cd ${WRKSRC} && \
	${CC} ${CPPFLAGS} -c srs-filter.c  &&  \
	${CC} -o srs-milter ${LDFLAGS} -lspf2 -lsrs2 -lpthread \
		 srs-filter.o ${BUILDLINK_PREFIX.libmilter}/lib/libmilter.a

do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} srs-milter ${DESTDIR}${PREFIX}/sbin

.include "../../mail/libspf2/buildlink3.mk"
.include "../../mail/libsrs2/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
