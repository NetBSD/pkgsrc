# $NetBSD: Makefile,v 1.20 2023/07/06 09:39:10 wiz Exp $

DISTNAME=	File-Find-Rule-Age-0.302
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Find-Rule-Age
COMMENT=	Rule to match on file age
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.42:../../time/p5-DateTime
DEPENDS+=	p5-File-Find-Rule>=0.30:../../devel/p5-File-Find-Rule

PERL5_PACKLIST=		auto/File/Find/Rule/Age/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
