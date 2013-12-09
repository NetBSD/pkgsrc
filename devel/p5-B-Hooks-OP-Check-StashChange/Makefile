# $NetBSD: Makefile,v 1.7 2013/12/09 14:17:43 obache Exp $

DISTNAME=	B-Hooks-OP-Check-StashChange-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/B-Hooks-OP-Check-StashChange/
COMMENT=	Invoke callbacks when the stash code is being compiled in changes
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-ExtUtils-Depends-[0-9]*:../../devel/p5-ExtUtils-Depends

DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/B/Hooks/OP/Check/StashChange/.packlist

.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
