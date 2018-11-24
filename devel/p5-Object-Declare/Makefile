# $NetBSD: Makefile,v 1.14 2018/11/24 11:50:06 wen Exp $
#

DISTNAME=	Object-Declare-0.24
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
