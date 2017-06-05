# $NetBSD: Makefile,v 1.16 2017/06/05 14:23:09 ryoon Exp $

DISTNAME=	IPC-SysV-2.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IPC-SysV/
COMMENT=	Perl module which defines+exports SysV IPC constants and system calls
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/IPC/SysV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
