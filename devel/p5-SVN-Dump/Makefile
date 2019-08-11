# $NetBSD: Makefile,v 1.15 2019/08/11 13:20:17 wiz Exp $

DISTNAME=	SVN-Dump-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SVN-Dump
COMMENT=	Perl interface to Subversion dumps
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/SVN/Dump/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
