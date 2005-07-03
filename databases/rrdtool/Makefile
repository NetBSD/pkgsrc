# $NetBSD: Makefile,v 1.31 2005/07/03 15:23:33 wulf Exp $
#

DISTNAME=	rrdtool-1.2.9
CATEGORIES=	databases graphics net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/pub/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/
COMMENT=	Data analysis tool generating graphical representations

#needs FPC code not found in older versions of NetBSD
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-alpha NetBSD-1.5-alpha \
			NetBSD-1.5.*-alpha NetBSD-1.5[A-U]-alpha

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

CONFIGURE_ARGS= --enable-shared

PERL5_CONFIGURE=	NO
PERL5_PACKLIST+= 	${PERL5_SITEARCH}/auto/RRDp/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/RRDs/.packlist

#INSTALL_DIRS=		${WRKSRC} \
#			${WRKSRC}/bindings/perl-piped \
#			${WRKSRC}/bindings/perl-shared

#post-extract:
#	${RM} ${WRKSRC}/bindings/perl-shared/ntmake.pl

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../www/cgilib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
