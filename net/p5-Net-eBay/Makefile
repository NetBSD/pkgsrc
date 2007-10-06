# $NetBSD: Makefile,v 1.3 2007/10/06 00:29:18 joerg Exp $

DISTNAME=		Net-eBay-0.41
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		net perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://www.net-ebay.org/
COMMENT=		Perl Interface to XML based eBay API

DEPENDS+=		p5-Crypt-SSLeay-[0-9]*:../../security/p5-Crypt-SSLeay
DEPENDS+=		p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay
DEPENDS+=		p5-XML-Dumper-[0-9]*:../../textproc/p5-XML-Dumper
DEPENDS+=		p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

REPLACE_PERL+=		*.pl

PERL5_PACKLIST=		auto/Net/eBay/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
