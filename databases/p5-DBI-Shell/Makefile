# $NetBSD: Makefile,v 1.30 2022/06/28 11:31:23 wiz Exp $

DISTNAME=	DBI-Shell-11.97
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBI-Shell
COMMENT=	Interactive command Shell for the Perl DBI
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Tee>=0.64:../../devel/p5-IO-Tee
DEPENDS+=	p5-Text-Reform>=1.11:../../textproc/p5-Text-Reform
DEPENDS+=	p5-Text-CSV_XS-[0-9]*:../../textproc/p5-Text-CSV_XS
DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-IO-Interactive-[0-9]*:../../devel/p5-IO-Interactive

PERL5_PACKLIST=		auto/DBI/Shell/.packlist

REPLACE_PERL+=	lib/DBI/Shell/SQLMinus.pm
REPLACE_PERL+=	bin/dbish

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
