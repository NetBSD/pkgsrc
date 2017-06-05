# $NetBSD: Makefile,v 1.32 2017/06/05 14:23:08 ryoon Exp $

DISTNAME=	IPC-Run-0.96
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IPC-Run/
COMMENT=	Perl module for interacting with child processes
LICENSE=	gnu-gpl-v2 OR artistic

# XXX Win32 will need Win32::Process while all others IO::Pty
#     How about Interix?
DEPENDS+=	p5-IO-tty>=1.08:../../devel/p5-IO-Tty

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IPC/Run/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
