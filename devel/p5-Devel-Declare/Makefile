# $NetBSD: Makefile,v 1.3 2008/11/02 23:34:14 he Exp $
#

DISTNAME=	Devel-Declare-0.003003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Declare/
COMMENT=	Declarator magic for perl

DEPENDS+=	p5-B-Hooks-EndOfScope>0:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-B-Hooks-OP-Check>=0.10:../../devel/p5-B-Hooks-OP-Check
DEPENDS+=	p5-Sub-Name>0:../../devel/p5-Sub-Name

BUILD_DEPENDS+=	p5-ExtUtils-Depends>0:../../devel/p5-ExtUtils-Depends

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Devel/Declare/.packlist

.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
