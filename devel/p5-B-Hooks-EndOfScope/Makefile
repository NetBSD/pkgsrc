# $NetBSD: Makefile,v 1.1.1.1 2008/11/02 22:14:58 he Exp $
#

DISTNAME=	B-Hooks-EndOfScope-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/B-Hooks-EndOfScope/
COMMENT=	Perl 5 module to execute code after a scope finished compilation

DEPENDS+=	p5-Scope-Guard>0:../../devel/p5-Scope-Guard
DEPENDS+=	p5-Sub-Exporter>0:../../devel/p5-Sub-Exporter

PKG_DESTDIR_SUPPORT=	user-destdir

#USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/B/Hooks/EndOfScope/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
