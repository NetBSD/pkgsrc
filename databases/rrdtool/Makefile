# $NetBSD: Makefile,v 1.34 2005/07/17 16:29:56 kristerw Exp $
#

DISTNAME=	rrdtool-1.2.10
CATEGORIES=	databases graphics net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/pub/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/
COMMENT=	Data analysis tool generating graphical representations

#needs FPC code not found in older versions of NetBSD
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-alpha NetBSD-1.5-alpha \
			NetBSD-1.5.*-alpha NetBSD-1.5[A-U]-alpha

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require

CONFIGURE_ARGS= --enable-shared

PERL5_CONFIGURE=	NO
PERL5_PACKLIST+= 	auto/RRDp/.packlist
PERL5_PACKLIST+=	auto/RRDs/.packlist

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../www/cgilib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
