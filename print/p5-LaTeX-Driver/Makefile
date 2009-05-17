# $NetBSD: Makefile,v 1.1.1.1 2009/05/17 10:20:36 sno Exp $
#

DISTNAME=	LaTeX-Driver-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LaTeX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LaTeX-Driver/
COMMENT=	Perl module encapsulates the details of invoking the Latex programs
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp

PERL5_PACKLIST=		auto/LaTeX/Driver/.packlist

TEX_ACCEPTED=	teTeX3

.include "../../lang/perl5/module.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
