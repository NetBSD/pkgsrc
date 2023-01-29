# $NetBSD: Makefile,v 1.43 2023/01/29 10:22:12 wiz Exp $

DISTNAME=	Finance-Quote-1.53
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Finance/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://finance-quote.sourceforge.net/
COMMENT=	Perl module to get stock quotes from various exchanges
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	p5-Carp-[0-9]*:../../devel/p5-Carp
DEPENDS+=	p5-Data-Dumper-[0-9]*:../../devel/p5-Data-Dumper
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Strptime-[0-9]*:../../time/p5-DateTime-Format-Strptime
# Encode - part of perl
# Exporter - part of perl
DEPENDS+=	p5-HTML-TableExtract>=1.0:../../www/p5-HTML-TableExtract
# HTML::TokeParser - part of p5-HTML-Parser
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-TokeParser-Simple-[0-9]*:../../www/p5-HTML-TokeParser-Simple
# HTML::TreeBuilder - part of p5-HTML-Tree
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-TreeBuilder-XPath-[0-9]*:../../www/p5-HTML-TreeBuilder-XPath
DEPENDS+=	p5-HTTP-Cookies-[0-9]*:../../www/p5-HTTP-Cookies
# HTTP::Headers - part of HTTP-Message
# HTTP::Request - part of HTTP-Message
# HTTP::Request::Common - part of HTTP-Message
# HTTP::Status - part of HTTP-Message
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
# IO::Handle - part of perl
# IO::Uncompress::Unzip - part of perl
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww
# Module::Load - part of perl
DEPENDS+=	p5-Mozilla-CA-[0-9]*:../../security/p5-Mozilla-CA
# POSIX - part of perl
# Scalar::Util - part of perl
DEPENDS+=	p5-Spreadsheet-XLSX-[0-9]*:../../math/p5-Spreadsheet-XLSX
DEPENDS+=	p5-String-Util-[0-9]*:../../devel/p5-String-Util
DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template
# Time::Piece - part of perl
# Time::Seconds - part of perl
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-Web-Scraper-[0-9]*:../../www/p5-Web-Scraper
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
# base - part of perl
# constant - part of perl
# if - part of perl
# strict - part of perl
# utf8 - part of perl
# vars - part of perl
# warnings - part of perl
TEST_DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
TEST_DEPENDS+=	p5-Date-Range-[0-9]*:../../time/p5-Date-Range
TEST_DEPENDS+=	p5-Date-Simple-[0-9]*:../../devel/p5-Date-Simple
# DateTime::Duration - part of DateTime
TEST_DEPENDS+=	p5-DateTime-Format-ISO8601-[0-9]*:../../time/p5-DateTime-Format-ISO8601
# File::Spec - part of perl
TEST_DEPENDS+=	p5-String-Util-[0-9]*:../../devel/p5-String-Util
TEST_DEPENDS+=	p5-Test-Kwalitee-[0-9]*:../../devel/p5-Test-Kwalitee
# Test::More - part of perl
TEST_DEPENDS+=	p5-Test-Perl-Critic-[0-9]*:../../devel/p5-Test-Perl-Critic
TEST_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
TEST_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
# feature - part of perl

REPLACE_PERL=	lib/Finance/Quote.pm
REPLACE_PERL+=	lib/Finance/Quote/*.pm

CONFLICTS=	p5-finance-quote-[0-9]*

USE_LANGUAGES=	# empty

PERL5_PACKLIST=		auto/Finance/Quote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
