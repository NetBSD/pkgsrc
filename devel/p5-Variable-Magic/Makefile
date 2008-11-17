# $NetBSD: Makefile,v 1.3 2008/11/17 22:37:49 he Exp $
#

DISTNAME=	Variable-Magic-0.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Variable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Variable-Magic/
COMMENT=	Perl 5 module to associate user-defined magic to variables

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Variable/Magic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
