# $NetBSD: Makefile,v 1.27 2017/06/05 14:24:08 ryoon Exp $

DISTNAME=	Sendmail-AccessDB-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sendmail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sendmail-AccessDB/
COMMENT=	Perl5 module for manipulating the sendmail accessdb
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB

PERL5_PACKLIST=		auto/Sendmail/AccessDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
