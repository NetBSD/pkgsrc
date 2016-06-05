# $NetBSD: Makefile,v 1.10 2016/06/05 04:57:39 wen Exp $
#

DISTNAME=	Object-Declare-0.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Object-Declare/
COMMENT=	Perl 5 module providing declarative object constructor
LICENSE=	mit

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Object/Declare/.packlist

DEPENDS+=	p5-Sub-Override-[0-9]*:../../devel/p5-Sub-Override

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
