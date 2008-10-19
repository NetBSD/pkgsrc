# $NetBSD: Makefile,v 1.12 2008/10/19 19:18:55 he Exp $

DISTNAME=	String-ShellQuote-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/String-ShellQuote/
COMMENT=	Quote strings for passing through the shell

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/String/ShellQuote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
