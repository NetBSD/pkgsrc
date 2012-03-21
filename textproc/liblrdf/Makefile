# $NetBSD: Makefile,v 1.5 2012/03/21 10:04:11 wiz Exp $
#

DISTNAME=	liblrdf-0.5.0
CATEGORIES=	textproc
MASTER_SITES=	# github download sucks for packaging

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	https://github.com/swh/LRDF
COMMENT=	Library for easy manipulation of LADSPA plugin RDF descriptions
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/swh-LRDF-7ebc032

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake pkg-config
USE_LANGUAGES=		c

PKGCONFIG_OVERRIDE+=	lrdf.pc.in

pre-configure:
	cd ${WRKSRC} && aclocal && autoheader && libtoolize && autoconf && automake -acf

.include "../../audio/ladspa/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
