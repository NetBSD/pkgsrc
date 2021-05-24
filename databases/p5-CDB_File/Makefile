# $NetBSD: Makefile,v 1.19 2021/05/24 19:49:31 wiz Exp $

DISTNAME=	CDB_File-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CDB_File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CDB_File
COMMENT=	Perl5 module to use CDB files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-B-COW>=0:../../devel/p5-B-COW

PERL5_PACKLIST=		auto/CDB_File/.packlist

REPLACE_PERL+=		bun-x.pl

.include "../../mk/bsd.prefs.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
