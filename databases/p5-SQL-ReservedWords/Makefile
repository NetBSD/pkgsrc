# $NetBSD: Makefile,v 1.13 2017/06/05 14:22:31 ryoon Exp $

DISTNAME=	SQL-ReservedWords-0.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SQL-ReservedWords/
COMMENT=	Reserved SQL words by standard and vendors
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

PERL5_PACKLIST=		auto/SQL/ReservedWords/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
