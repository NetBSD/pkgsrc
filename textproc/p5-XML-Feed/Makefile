# $NetBSD: Makefile,v 1.1.1.1 2007/04/30 22:57:59 heinz Exp $
#

DISTNAME=		XML-Feed-0.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5xfe
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/XML-Feed/
COMMENT=		Perl syndication feed parser for both RSS and Atom feeds

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Class-ErrorHandler-[0-9]*:../../devel/p5-Class-ErrorHandler
DEPENDS+=		p5-Feed-Find-[0-9]*:../../textproc/p5-Feed-Find
DEPENDS+=		p5-URI-Fetch-[0-9]*:../../www/p5-URI-Fetch
DEPENDS+=		p5-XML-Atom>=0.08:../../textproc/p5-XML-Atom
DEPENDS+=		p5-XML-RSS>=1.01:../../textproc/p5-XML-RSS
DEPENDS+=		p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=		p5-DateTime-Format-Mail-[0-9]*:../../time/p5-DateTime-Format-Mail
DEPENDS+=		p5-DateTime-Format-W3CDTF-[0-9]*:../../time/p5-DateTime-Format-W3CDTF

BUILD_DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
BUILD_DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

MAKE_ENV+=		PERL_EXTUTILS_AUTOINSTALL=--defaultdeps
PERL5_PACKLIST=		auto/XML/Feed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
