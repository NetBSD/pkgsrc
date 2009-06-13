# $NetBSD: Makefile,v 1.4 2009/06/13 06:46:48 rillig Exp $

DISTNAME=	signatures-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FL/FLORA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?signatures
COMMENT=	Subroutine signatures with no source filter

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/signatures/.packlist

BUILD_DEPENDS+=    p5-ExtUtils-Depends>0:../../devel/p5-ExtUtils-Depends

DEPENDS+=	p5-B-Hooks-OP-Check>=0.17:../../devel/p5-B-Hooks-OP-Check
DEPENDS+=	p5-B-Hooks-OP-PPAddr>=0:../../devel/p5-B-Hooks-OP-PPAddr
DEPENDS+=	p5-B-Hooks-Parser>=0.07:../../devel/p5-B-Hooks-Parser
DEPENDS+=	p5-B-Hooks-EndOfScope>=0.08:../../devel/p5-B-Hooks-EndOfScope

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../devel/p5-B-Hooks-OP-PPAddr/buildlink3.mk"
.include "../../devel/p5-B-Hooks-Parser/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
