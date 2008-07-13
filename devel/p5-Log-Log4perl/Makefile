# $NetBSD: Makefile,v 1.1.1.1 2008/07/13 15:23:10 rhaen Exp $
#

DISTNAME=	Log-Log4perl-1.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://log4perl.sourceforge.net/
COMMENT=	Log::Log4perl - Log4j implementation for Perl

PERL5_PACKLIST=	auto/Log/Log4perl/.packlist
PKG_DESTDIR_SUPPORT=user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
