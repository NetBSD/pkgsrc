# $NetBSD: Makefile,v 1.26 2012/09/14 14:28:52 sno Exp $
#

DISTNAME=	NetAddr-IP-4.062
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nai
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetAddr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/NetAddr-IP/
COMMENT=	Perl5 module for managing IP addresses
LICENSE=	artistic OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# This is for the 'test' target
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

REPLACE_PERL+=	IP.pm
REPLACE_PERL+=	Lite/Lite.pm
REPLACE_PERL+=	Lite/Util/Util.pm
REPLACE_PERL+=	Lite/Util/lib/NetAddr/IP/UtilPP.pm
REPLACE_PERL+=	Lite/Util/tlib/NetAddr/IP/Util_IS.pm

SUBST_CLASSES+=	fixperl
SUBST_STAGE.fixperl=	pre-configure
SUBST_MESSAGE.fixperl=	Fixing perl interpreter
SUBST_FILES.fixperl+=	Lite/Util/Makefile.PL
SUBST_SED.fixperl=	-e 's,/usr/bin/perl,${PERL5},'

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/NetAddr/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
