# $NetBSD: Makefile,v 1.8 2013/12/09 14:17:42 obache Exp $

DISTNAME=	DBIx-Class-DigestColumns-0.06000
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?DBIx::Class::DigestColumns
COMMENT=	Automatic digest columns for DBIx::Class

DEPENDS+=	p5-DBIx-Class>=0.06002:../../databases/p5-DBIx-Class
DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5>=0}:../../security/p5-Digest-MD5

BUILD_DEPENDS+= p5-DBD-SQLite>=1.11:../../databases/p5-DBD-SQLite

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/DigestColumns/.packlist

PERL5_MODULE_TYPE= 	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
