# $NetBSD: Makefile,v 1.41 2017/06/05 14:22:45 ryoon Exp $

DISTNAME=	Config-General-2.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.daemon.de/ConfigGeneral
COMMENT=	Perl Generic Config module
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Config/General/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
