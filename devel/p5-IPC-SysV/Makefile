# $NetBSD: Makefile,v 1.19 2019/08/11 13:19:41 wiz Exp $

DISTNAME=	IPC-SysV-2.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IPC-SysV
COMMENT=	Perl module which defines+exports SysV IPC constants and system calls
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/IPC/SysV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
