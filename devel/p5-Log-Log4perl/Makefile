# $NetBSD: Makefile,v 1.12 2010/02/15 16:05:27 sno Exp $
#

DISTNAME=	Log-Log4perl-1.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://log4perl.sourceforge.net/
COMMENT=	Log::Log4perl - Log4j implementation for Perl
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Log/Log4perl/.packlist
PKG_DESTDIR_SUPPORT=user-destdir

REPLACE_PERL+=	lib/Log/Log4perl/Layout/PatternLayout/Multiline.pm

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
