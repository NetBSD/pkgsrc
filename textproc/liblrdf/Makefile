# $NetBSD: Makefile,v 1.33 2020/11/05 09:07:10 ryoon Exp $

DISTNAME=	liblrdf-0.6.1
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=swh/}
GITHUB_PROJECT=	LRDF
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/swh/LRDF
COMMENT=	Library for easy manipulation of LADSPA plugin RDF descriptions
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoreconf autoconf automake
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	lrdf.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../audio/ladspa/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
