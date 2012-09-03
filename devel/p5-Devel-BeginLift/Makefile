# $NetBSD: Makefile,v 1.2 2012/09/03 11:16:22 sno Exp $

DISTNAME=	Devel-BeginLift-0.001003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Declare/
COMMENT=	Declarator magic for perl
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-ExtUtils-Depends-[0-9]*:../../devel/p5-ExtUtils-Depends

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Devel/BeginLift/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

BUILDLINK_DEPMETHOD.p5-B-Hooks-OP-Check=	full
BUILDLINK_API_DEPENDS.p5-B-Hooks-OP-Check+=	p5-B-Hooks-OP-Check>=0.19

.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../devel/p5-B-Hooks-OP-Check-EntersubForCV/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
