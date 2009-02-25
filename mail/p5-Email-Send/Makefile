# $NetBSD: Makefile,v 1.9 2009/02/25 20:51:11 sno Exp $

DISTNAME=	Email-Send-2.194
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Send/
COMMENT=	Email::Send - Simply Sending Email

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Email-Address>=1.80:../../mail/p5-Email-Address
DEPENDS+=	p5-Email-Simple>=1.92:../../mail/p5-Email-Simple
DEPENDS+=	p5-Module-Pluggable>=2.97:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Return-Value>=1.28:../../devel/p5-Return-Value

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Email/Send/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
