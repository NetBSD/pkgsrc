# $NetBSD: Makefile,v 1.26 2019/08/11 13:18:25 wiz Exp $

DISTNAME=	DBI-Shell-11.95
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBI-Shell
COMMENT=	Interactive command Shell for the Perl DBI

DEPENDS+=	p5-IO-Tee>=0.64:../../devel/p5-IO-Tee
DEPENDS+=	p5-Text-Reform>=1.11:../../textproc/p5-Text-Reform

PERL5_PACKLIST=		auto/DBI/Shell/.packlist

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.37

REPLACE_PERL+=	lib/DBI/Shell/SQLMinus.pm

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
