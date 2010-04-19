# $NetBSD: Makefile,v 1.1.1.1 2010/04/19 22:47:11 seb Exp $
#

DISTNAME=	Net-Server-Coro-0.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Server-Coro/
COMMENT=	Perl 5 co-operative multithreaded server using Coro
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/Server/Coro/.packlist

DEPENDS+=	p5-Coro-[0-9]*:../../devel/p5-Coro
DEPENDS+=	p5-EV-[0-9]*:../../devel/p5-EV
DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Net-Server-[0-9]*:../../net/p5-Net-Server

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
