# $NetBSD: Makefile,v 1.27 2018/08/22 09:47:06 wiz Exp $

DISTNAME=		XML-Feed-0.53
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/XML-Feed/
COMMENT=		Perl syndication feed parser for both RSS and Atom feeds
LICENSE=		gnu-gpl-v2 # OR artistic

DEPENDS+=		p5-Class-ErrorHandler-[0-9]*:../../devel/p5-Class-ErrorHandler
DEPENDS+=		p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=		p5-DateTime-Format-Mail-[0-9]*:../../time/p5-DateTime-Format-Mail
DEPENDS+=		p5-DateTime-Format-W3CDTF-[0-9]*:../../time/p5-DateTime-Format-W3CDTF
DEPENDS+=		p5-Feed-Find-[0-9]*:../../textproc/p5-Feed-Find
DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
#DEPENDS+=		{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
DEPENDS+=		p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
DEPENDS+=		p5-URI-Fetch-[0-9]*:../../www/p5-URI-Fetch
DEPENDS+=		p5-XML-Atom>=0.38:../../textproc/p5-XML-Atom
DEPENDS+=		p5-XML-LibXML>=1.66:../../textproc/p5-XML-LibXML
DEPENDS+=		p5-XML-RSS>=1.47:../../textproc/p5-XML-RSS

MAKE_ENV+=		PERL_EXTUTILS_AUTOINSTALL=--defaultdeps
PERL5_PACKLIST=		auto/XML/Feed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
