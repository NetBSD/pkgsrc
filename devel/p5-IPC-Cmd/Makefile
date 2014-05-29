# $NetBSD: Makefile,v 1.17 2014/05/29 23:36:00 wiz Exp $

DISTNAME=	IPC-Cmd-0.90
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IPC-Cmd/
COMMENT=	Perl module for finding and running system commands
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IPC/Cmd/.packlist

PERL5_REQD+=		5.10.0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
