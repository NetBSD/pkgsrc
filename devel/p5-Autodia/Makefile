# $NetBSD: Makefile,v 1.16 2023/07/06 09:38:37 wiz Exp $

DISTNAME=	Autodia-2.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TE/TEEJAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Autodia
COMMENT=	Create documentation through templates
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
TOOL_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

PERL5_PACKLIST=	auto/Autodia/.packlist
REPLACE_PERL=	autodia.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
