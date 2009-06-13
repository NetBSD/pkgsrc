# $NetBSD: Makefile,v 1.4 2009/06/13 06:46:47 rillig Exp $
#

DISTNAME=	Test-Script-1.03
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=	p5ts
PKGREVISION=	1
CATEGORIES=	perl5 devel
#MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/A/AD/ADAMK/
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AD/ADAMK/
COMMENT=	Test::Script - Cross-platform basic tests for scripts

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-IPC-Run3>=0.039:../../devel/p5-IPC-Run3

PERL5_PACKLIST=		auto/Test/Script/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
