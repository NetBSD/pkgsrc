# $NetBSD: Makefile,v 1.8 2013/05/31 12:40:26 wiz Exp $

DISTNAME=	IPC-SysV-2.03
PKGNAME=	p5-${DISTNAME:S/_/beta/}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IPC-SysV/
COMMENT=	Perl module which defines+exports SysV IPC constants and system calls
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/IPC/SysV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
