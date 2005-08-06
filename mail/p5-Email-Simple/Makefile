# $NetBSD: Makefile,v 1.3 2005/08/06 06:19:21 jlam Exp $

DISTNAME=		Email-Simple-1.92
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ems
PKGREVISION=		1
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Email-Simple/
COMMENT=		Perl5 module for simple parsing of RFC2822 message format and headers

PERL5_PACKLIST=		auto/Email/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
