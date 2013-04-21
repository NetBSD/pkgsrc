# $NetBSD: Makefile,v 1.23 2013/04/21 11:39:57 ryoon Exp $

DISTNAME=	IPC-Run-0.92
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IPC-Run/
COMMENT=	Perl module for interacting with child processes
LICENSE=	gnu-gpl-v2 OR artistic

# XXX Win32 will need Win32::Process while all others IO::Pty
#     How about Interix?
DEPENDS+=	p5-IO-tty>=1.08:../../devel/p5-IO-Tty

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IPC/Run/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
