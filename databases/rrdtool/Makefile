# $NetBSD: Makefile,v 1.40 2005/10/02 00:09:40 wulf Exp $
#

DISTNAME=	rrdtool-1.2.11
PKGREVISION=	2
CATEGORIES=	databases graphics net
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/rrdtool/pub/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://people.ee.ethz.ch/~oetiker/webtools/rrdtool/
COMMENT=	Data analysis tool generating graphical representations

#needs FPC code not found in older versions of NetBSD
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-alpha NetBSD-1.5-alpha \
			NetBSD-1.5.*-alpha NetBSD-1.5[A-U]-alpha

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require

CONFIGURE_ARGS=		--enable-shared
CONFIGURE_ARGS+=	--with-perl-options=${MAKE_PARAMS:Q}

PERL5_CONFIGURE=	NO
PERL5_PACKLIST+= 	auto/RRDp/.packlist
PERL5_PACKLIST+=	auto/RRDs/.packlist

RRDDOCDIR=		${PREFIX}/share/doc/rrdtool

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../www/cgilib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
