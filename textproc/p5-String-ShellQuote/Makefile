# $NetBSD: Makefile,v 1.6 2004/12/20 11:31:09 grant Exp $

DISTNAME=	String-ShellQuote-1.00
PKGNAME=	p5-String-ShellQuote-1.00
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=String::ShellQuote
COMMENT=	Quote strings for passing through the shell

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/String/ShellQuote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
