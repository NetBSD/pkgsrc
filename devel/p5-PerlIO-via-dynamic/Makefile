# $NetBSD: Makefile,v 1.11 2011/08/14 12:26:31 obache Exp $

DISTNAME=	PerlIO-via-dynamic-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PerlIO-via-dynamic/
COMMENT=	Perl module for dynamic PerlIO layers

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/PerlIO/via/dynamic/.packlist

# The following DEPENDS applies only if the perl version is 5.10,
# but there's no way to specify that kind of condition, and it's
# probably safe to make the dependency unconditional.
DEPENDS+= p5-Internals>=1.1:../../devel/p5-Internals

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
