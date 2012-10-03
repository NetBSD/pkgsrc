# $NetBSD: Makefile,v 1.16 2012/10/03 21:57:59 wiz Exp $

DISTNAME=	String-ShellQuote-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/String-ShellQuote/
COMMENT=	Quote strings for passing through the shell
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/String/ShellQuote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
