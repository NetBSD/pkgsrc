# $NetBSD: Makefile,v 1.29 2023/07/06 09:41:47 wiz Exp $

DISTNAME=	String-ShellQuote-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/String-ShellQuote
COMMENT=	Quote strings for passing through the shell
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty

PERL5_PACKLIST=		auto/String/ShellQuote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
