# $NetBSD: Makefile,v 1.13 2017/06/05 14:24:45 ryoon Exp $

DISTNAME=	String-BufferStack-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
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
