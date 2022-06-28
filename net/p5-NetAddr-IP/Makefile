# $NetBSD: Makefile,v 1.48 2022/06/28 11:35:15 wiz Exp $

DISTNAME=	NetAddr-IP-4.079
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetAddr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/NetAddr-IP
COMMENT=	Perl5 module for managing IP addresses
LICENSE=	artistic OR gnu-gpl-v2

# This is for the 'test' target
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

REPLACE_PERL+=	IP.pm
REPLACE_PERL+=	Lite/Lite.pm
REPLACE_PERL+=	Lite/Util/Util.pm
REPLACE_PERL+=	Lite/Util/lib/NetAddr/IP/UtilPP.pm
REPLACE_PERL+=	Lite/Util/tlib/NetAddr/IP/Util_IS.pm

SUBST_CLASSES+=		fixperl
SUBST_STAGE.fixperl=	pre-configure
SUBST_MESSAGE.fixperl=	Fixing perl interpreter
SUBST_FILES.fixperl+=	Lite/Util/Makefile.PL
SUBST_SED.fixperl=	-e 's,/usr/bin/perl,${PERL5},'

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/NetAddr/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
