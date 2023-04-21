# $NetBSD: Makefile,v 1.1 2023/04/21 00:49:56 manu Exp $

GITHUB_PROJECT=	OpenARC
GITHUB_TAG=	355ee2a1ca85acccce494478991983b54f794f4e
DISTNAME=	openarc-20180921
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=trusteddomainproject/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trusteddomainproject/OpenARC
COMMENT=	Open source ARC library, MTA filter implementation and tools
LICENSE=	modified-bsd

RCD_SCRIPTS=	openarc

USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf automake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-milter=${BUILDLINK_PREFIX.libmilter}

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	${EGDIR}

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf

post-install:
	${INSTALL_DATA} ${WRKSRC}/openarc/openarc.conf.sample \
		${DESTDIR}${EGDIR}/

.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
