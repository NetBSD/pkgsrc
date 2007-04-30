# $NetBSD: Makefile,v 1.1.1.1 2007/04/30 21:53:16 heinz Exp $
#

DISTNAME=		Feed-Find-0.06
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ffi
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/B/BT/BTROTT/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Feed-Find/
COMMENT=		Perl module to perform autodiscovery of syndication feeds

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=		p5-Class-ErrorHandler-[0-9]*:../../devel/p5-Class-ErrorHandler
DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI

USE_LANGUAGES=		# empty

MAKE_ENV+=		PERL_EXTUTILS_AUTOINSTALL=--defaultdeps
PERL5_PACKLIST=		auto/Feed/Find/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
