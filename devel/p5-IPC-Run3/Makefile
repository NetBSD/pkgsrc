# $NetBSD: Makefile,v 1.27 2024/08/11 01:29:57 wen Exp $

DISTNAME=	IPC-Run3-0.049
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/IPC::Run3
COMMENT=	IPC::Run3 - run a subprocess in batch mode
LICENSE=	original-bsd OR artistic OR gnu-gpl-v2

PERL5_PACKLIST=	auto/IPC/Run3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
