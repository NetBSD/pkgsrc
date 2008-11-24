# $NetBSD: Makefile,v 1.1.1.1 2008/11/24 06:00:32 seb Exp $
#

DISTNAME=	Net-Akismet-0.05
PKGNAME=	p5-${DISTNAME}
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
