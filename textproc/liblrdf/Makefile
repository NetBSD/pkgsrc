# $NetBSD: Makefile,v 1.23 2019/07/01 04:07:52 ryoon Exp $
#

DISTNAME=	liblrdf-0.5.0
PKGREVISION=	15
CATEGORIES=	textproc
MASTER_SITES=	# github download sucks for packaging

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/swh/LRDF
COMMENT=	Library for easy manipulation of LADSPA plugin RDF descriptions
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/swh-LRDF-7ebc032

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		autoreconf aclocal autoconf autoheader automake pkg-config
USE_LANGUAGES=		c

PKGCONFIG_OVERRIDE+=	lrdf.pc.in

pre-configure:
	cd ${WRKSRC} && rm m4/* && autoreconf -fi

.include "../../audio/ladspa/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
