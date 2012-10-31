# $NetBSD: Makefile,v 1.7 2012/10/31 11:18:24 asau Exp $

DISTNAME=	IPC-SysV-2.03
PKGNAME=	p5-${DISTNAME:S/_/beta/}
PKGREVISION=	3
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
