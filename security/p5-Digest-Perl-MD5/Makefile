# $NetBSD: Makefile,v 1.13 2019/08/11 13:22:57 wiz Exp $

DISTNAME=	Digest-Perl-MD5-1.9
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Digest-Perl-MD5
COMMENT=	Perl implementation of Ron Rivests MD5 Algorithm
LICENSE=	${PERL5_LICENSE}

CHECK_INTERPRETER_SKIP+= ${PERL5_SUB_INSTALLVENDORLIB}/Digest/Perl/MD5.pm

#DEPENDS+=	{perl>=5.7.3,p5-Digest>=1.00}:../../security/p5-Digest

PERL5_PACKLIST=		auto/Digest/Perl/MD5/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
