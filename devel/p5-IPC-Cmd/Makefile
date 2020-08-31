# $NetBSD: Makefile,v 1.32 2020/08/31 18:08:13 wiz Exp $

DISTNAME=	IPC-Cmd-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IPC-Cmd
COMMENT=	Perl module for finding and running system commands
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IPC/Cmd/.packlist

PERL5_REQD+=		5.10.0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
