# $NetBSD: Makefile,v 1.23 2022/06/28 11:35:15 wiz Exp $

DISTNAME=		Net-eBay-0.61
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		net perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://www.net-ebay.org/
#HOMEPAGE=		http://search.cpan.org/dist/Net-eBay/
COMMENT=		Perl Interface to XML based eBay API
LICENSE=		gnu-gpl-v2

DEPENDS+=		p5-Crypt-SSLeay-[0-9]*:../../security/p5-Crypt-SSLeay
DEPENDS+=		p5-DateTime-Precise-[0-9]*:../../time/p5-DateTime-Precise
DEPENDS+=		p5-HTML-Format-[0-9]*:../../www/p5-HTML-Format
DEPENDS+=		p5-HTML-PrettyPrinter-[0-9]*:../../www/p5-HTML-PrettyPrinter
DEPENDS+=		p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=		p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay
DEPENDS+=		p5-Text-Format-[0-9]*:../../textproc/p5-Text-Format
DEPENDS+=		p5-XML-Dumper-[0-9]*:../../textproc/p5-XML-Dumper
DEPENDS+=		p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

REPLACE_PERL+=		*.pl

PERL5_PACKLIST=		auto/Net/eBay/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
