# $NetBSD: Makefile,v 1.22 2017/06/05 14:24:46 ryoon Exp $

DISTNAME=	String-ShellQuote-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/String-ShellQuote/
COMMENT=	Quote strings for passing through the shell
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty

PERL5_PACKLIST=		auto/String/ShellQuote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
