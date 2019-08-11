# $NetBSD: Makefile,v 1.20 2019/08/11 13:21:31 wiz Exp $

DISTNAME=	Email-Date-Format-1.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Email-Date-Format
COMMENT=	Perl Module to produce RFC 2822 date strings
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5,p5-Time-Local-[0-9]*}:../../time/p5-Time-Local

PERL5_PACKLIST=	auto/Email/Date/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
