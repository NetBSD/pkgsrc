# $NetBSD: Makefile,v 1.8 2023/07/06 09:41:58 wiz Exp $

DISTNAME=	Win32-ShellQuote-0.003001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Win32/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Win32-ShellQuote
COMMENT=	Quote argument lists for Win32
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Win32/ShellQuote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
