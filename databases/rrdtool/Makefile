# $NetBSD: Makefile,v 1.27 2004/10/03 00:13:23 tv Exp $
#

DISTNAME=	rrdtool-1.0.40
PKGREVISION=	4
CATEGORIES=	databases graphics net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/pub/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/
COMMENT=	Data analysis tool generating graphical representations

#needs FPC code not found in older versions of NetBSD
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-alpha NetBSD-1.5-alpha \
			NetBSD-1.5.*-alpha NetBSD-1.5[A-U]-alpha

USE_LIBTOOL=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

CONFIGURE_ARGS= --enable-shared
CONFIGURE_ENV=	PERL=${PERL5}

PERL5_CONFIGURE=	NO
PERL5_PACKLIST+= 	${PERL5_SITEARCH}/auto/RRDp/.packlist
PERL5_PACKLIST+=	${PERL5_SITEARCH}/auto/RRDs/.packlist

INSTALL_DIRS=	${WRKSRC} ${WRKSRC}/perl-piped ${WRKSRC}/perl-shared

# remove this or else it is installed
post-extract:
	${RM} ${WRKSRC}/perl-shared/ntmake.pl

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../www/cgilib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
