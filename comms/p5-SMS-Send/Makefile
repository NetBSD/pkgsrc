# $NetBSD: Makefile,v 1.1.1.1 2011/05/17 10:31:52 dmcmahill Exp $

DISTNAME=	SMS-Send-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AD/ADAMK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SMS-Send/
COMMENT=	Driver-based API for sending SMS messages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	perl>=5.8,p5-Module-Pluggable>=2.5:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Params-Util>=0.14:../../devel/p5-Params-Util
DEPENDS+=	p5-Class-Adapter>=1.00:../../devel/p5-Class-Adapter

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/SMS/Send/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
