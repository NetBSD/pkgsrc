# $NetBSD: Makefile,v 1.19 2022/06/28 11:32:29 wiz Exp $
#

DISTNAME=	Format-Human-Bytes-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Format/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Format-Human-Bytes
COMMENT=	Perl 5 module to format a bytecount and make it human readable
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Format/Human/Bytes/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
