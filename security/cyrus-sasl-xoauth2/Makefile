# $NetBSD: Makefile,v 1.1 2020/06/12 13:41:41 ryoon Exp $

DISTNAME=		cyrus-sasl-xoauth2-0.0.0.20200428
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=moriyoshi/}
GITHUB_PROJECT=		cyrus-sasl-xoauth2
GITHUB_TAG=		43d03523fecf0d580eec6cb5ac81ac54b93788df

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://github.com/moriyoshi/cyrus-sasl-xoauth2
COMMENT=		XOAUTH2 mechanism plugin for cyrus-sasl
LICENSE=		mit

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		automake
CONFIGURE_ARGS+=	--with-cyrus-sasl=${BUILDLINK_PREFIX.cyrus-sasl}

pre-configure:
	set -e; cd ${WRKSRC}; \
	${SH} ./autogen.sh

BUILDLINK_DEPMETHOD.cyrus-sasl=	build
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
