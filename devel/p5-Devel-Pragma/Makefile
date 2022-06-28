# $NetBSD: Makefile,v 1.19 2022/06/28 11:32:18 wiz Exp $

DISTNAME=	Devel-Pragma-1.1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Pragma
COMMENT=	Perl5 helper functions for developers of lexical pragmas
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-B-Hooks-EndOfScope>0.09:../../devel/p5-B-Hooks-EndOfScope
#see b3.mk include list at end
#DEPENDS+=	p5-B-Hooks-OP-Annotation>0.43:../../devel/p5-B-Hooks-OP-Annotation
#DEPENDS+=	p5-B-Hooks-OP-Check>0.18:../../devel/p5-B-Hooks-OP-Check
BUILD_DEPENDS+=	p5-ExtUtils-Depends>=0.302:../../devel/p5-ExtUtils-Depends

USE_LANGUAGES=					c
PERL5_PACKLIST=					auto/Devel/Pragma/.packlist
BUILDLINK_DEPMETHOD.p5-B-Hooks-OP-Check=	full
BUILDLINK_API_DEPENDS.p5-B-Hooks-OP-Check+=	p5-B-Hooks-OP-Check>=0.18

.include "../../devel/p5-B-Hooks-OP-Annotation/buildlink3.mk"
.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
