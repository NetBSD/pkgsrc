# $NetBSD: Makefile,v 1.33 2016/06/08 19:22:34 wiz Exp $

DISTNAME=	AppConfig-1.71
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AppConfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AppConfig/
COMMENT=	Perl5 module for parsing config files and command line arguments
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/AppConfig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
