# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:13 obache Exp $

DISTNAME=	IPC-SysV-2.03
PKGNAME=	p5-${DISTNAME:S/_/beta/}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IPC-SysV/
COMMENT=	Perl module which defines+exports SysV IPC constants and system calls
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/IPC/SysV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
