# $NetBSD: Makefile,v 1.5 2011/12/13 12:29:02 hiramatsu Exp $
#

DISTNAME=	lib-abs-0.92
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/lib-abs/
COMMENT=	Perl 5 module to add in @INC absolute paths from relative ones
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/lib/abs/.packlist
PERL5_MODULE_TYPE=	Module::Install # to handle auto_install flags properly

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
