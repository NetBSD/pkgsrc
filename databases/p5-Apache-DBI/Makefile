# $NetBSD: Makefile,v 1.38 2021/05/24 19:49:31 wiz Exp $

DISTNAME=	Apache-DBI-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Apache-DBI
COMMENT=	DBI support for Apache+mod_perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Digest-SHA1>=2.01:../../security/p5-Digest-SHA1

PERL5_PACKLIST=		auto/Apache/DBI/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
