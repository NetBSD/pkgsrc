# $NetBSD: Makefile,v 1.22 2018/08/22 09:44:33 wiz Exp $

DISTNAME=	PerlIO-via-dynamic-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AL/ALEXMV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PerlIO-via-dynamic/
COMMENT=	Perl module for dynamic PerlIO layers

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/PerlIO/via/dynamic/.packlist

# The following DEPENDS applies only if the perl version is 5.10,
# but there's no way to specify that kind of condition, and it's
# probably safe to make the dependency unconditional.
DEPENDS+= p5-Internals>=1.1:../../devel/p5-Internals

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
