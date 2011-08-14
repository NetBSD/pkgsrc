# $NetBSD: Makefile,v 1.3 2011/08/14 14:14:42 obache Exp $
#

DISTNAME=	Net-Akismet-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Akismet/
COMMENT=	Perl 5 interface to Akismet - comment and trackback spam fighter

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		# empty

DEPENDS+=	p5-libwww>=5.09:../../www/p5-libwww

PERL5_PACKLIST=		auto/Net/Akismet/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
