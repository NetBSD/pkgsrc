# $NetBSD: Makefile,v 1.8 2009/04/29 20:06:17 sno Exp $
#

DISTNAME=	Log-Log4perl-1.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://log4perl.sourceforge.net/
COMMENT=	Log::Log4perl - Log4j implementation for Perl
LICENSE=	gnu-gpl-v2 # OR artistic

PERL5_PACKLIST=	auto/Log/Log4perl/.packlist
PKG_DESTDIR_SUPPORT=user-destdir

REPLACE_PERL+=	lib/Log/Log4perl/Layout/PatternLayout/Multiline.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
