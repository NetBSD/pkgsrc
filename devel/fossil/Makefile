# $NetBSD: Makefile,v 1.42 2017/04/22 14:30:58 joerg Exp $

DISTNAME=	fossil-src-2.2
PKGNAME=	${DISTNAME:S/-src//}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	devel scm
MASTER_SITES=	https://www.fossil-scm.org/index.html/uv/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fossil-scm.org/
COMMENT=	High-reliability, distributed software configuration management
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl:Q}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib:Q}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/${PKGBASE}

pre-configure:
	${MKDIR} ${WRKSRC}/bld

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fossil ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fossil.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT-BSD2.txt \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/src/linenoise.h \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
