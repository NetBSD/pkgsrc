# $NetBSD: Makefile,v 1.4 2018/11/25 13:12:30 wen Exp $

DISTNAME=	Test-HTTP-LocalServer-0.64
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://cpan.metacpan.org/authors/id/C/CO/CORION/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::HTTP::LocalServer
COMMENT=	Perl module for spawning a local HTTP server for testing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-HTTP-Request-AsCGI-[0-9]*:../../www/p5-HTTP-Request-AsCGI

PERL5_PACKLIST=	auto/Test/HTTP/LocalServer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
