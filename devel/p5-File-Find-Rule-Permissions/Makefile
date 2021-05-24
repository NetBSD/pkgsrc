# $NetBSD: Makefile,v 1.20 2021/05/24 19:50:40 wiz Exp $

DISTNAME=	File-Find-Rule-Permissions-2.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Find-Rule-Permissions
COMMENT=	Rule to match on file permissions and user access
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-CheckOS>=1:../../devel/p5-Devel-CheckOS
DEPENDS+=	p5-File-Find-Rule>=0.10:../../devel/p5-File-Find-Rule

PERL5_PACKLIST=		auto/File/Find/Rule/Permissions/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
