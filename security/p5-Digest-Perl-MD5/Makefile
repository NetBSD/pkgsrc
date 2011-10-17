# $NetBSD: Makefile,v 1.2 2011/10/17 00:02:59 sbd Exp $

DISTNAME=	Digest-Perl-MD5-1.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-Perl-MD5/
COMMENT=	Perl implementation of Ron Rivests MD5 Algorithm
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

CHECK_INTERPRETER_SKIP+= ${PERL5_SUB_INSTALLVENDORLIB}/Digest/Perl/MD5.pm

#DEPENDS+=	{perl>=5.7.3,p5-Digest>=1.00}:../../security/p5-Digest

PERL5_PACKLIST=		auto/Digest/Perl/MD5/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
