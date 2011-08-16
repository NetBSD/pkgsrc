# $NetBSD: Makefile,v 1.1.1.1 2011/08/16 22:30:06 wiz Exp $

DISTNAME=	Digest-Perl-MD5-1.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-Perl-MD5/
COMMENT=	Perl implementation of Ron Rivests MD5 Algorithm
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

#DEPENDS+=	{perl>=5.7.3,p5-Digest>=1.00}:../../security/p5-Digest

PERL5_PACKLIST=		auto/Digest/Perl/MD5/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
