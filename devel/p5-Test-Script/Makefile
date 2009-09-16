# $NetBSD: Makefile,v 1.5 2009/09/16 17:25:52 sno Exp $
#

DISTNAME=	Test-Script-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AD/ADAMK/
COMMENT=	Test::Script - Cross-platform basic tests for scripts
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-IPC-Run3>=0.039:../../devel/p5-IPC-Run3

PERL5_PACKLIST=		auto/Test/Script/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
