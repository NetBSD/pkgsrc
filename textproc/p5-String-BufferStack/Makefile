# $NetBSD: Makefile,v 1.11 2015/06/12 10:51:28 wiz Exp $

DISTNAME=	String-BufferStack-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/String-BufferStack/
COMMENT=	Perl 5 module for nested buffers for templating systems
LICENSE=	artistic

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/String/BufferStack/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
