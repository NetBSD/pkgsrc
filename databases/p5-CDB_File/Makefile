# $NetBSD: Makefile,v 1.13 2017/06/05 14:22:23 ryoon Exp $

DISTNAME=	CDB_File-0.99
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CDB_File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CDB_File/
COMMENT=	Perl5 module to use CDB files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CDB_File/.packlist

REPLACE_PERL+=		bun-x.pl

.include "../../mk/bsd.prefs.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
