# $NetBSD: Makefile,v 1.34 2023/07/06 09:40:50 wiz Exp $

DISTNAME=	Sendmail-AccessDB-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sendmail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sendmail-AccessDB
COMMENT=	Perl5 module for manipulating the sendmail accessdb
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB

PERL5_PACKLIST=		auto/Sendmail/AccessDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
