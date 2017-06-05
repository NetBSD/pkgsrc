# $NetBSD: Makefile,v 1.12 2017/06/05 14:23:12 ryoon Exp $
#

DISTNAME=	Log-Trace-1.070
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Trace/
COMMENT=	Perl 5 module providing a unified approach to tracing
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Log/Trace/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
