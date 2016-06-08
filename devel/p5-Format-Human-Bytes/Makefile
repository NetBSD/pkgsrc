# $NetBSD: Makefile,v 1.11 2016/06/08 19:22:59 wiz Exp $
#

DISTNAME=	Format-Human-Bytes-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Format/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Format-Human-Bytes/
COMMENT=	Perl 5 module to format a bytecount and make it human readable
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Format/Human/Bytes/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
