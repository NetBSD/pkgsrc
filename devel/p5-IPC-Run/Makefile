# $NetBSD: Makefile,v 1.42 2023/02/12 11:01:43 wen Exp $

DISTNAME=	IPC-Run-20220807.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IPC-Run
COMMENT=	Perl module for interacting with child processes
LICENSE=	gnu-gpl-v2 OR artistic

# XXX Win32 will need Win32::Process while all others IO::Pty
#     How about Interix?
DEPENDS+=	p5-IO-tty>=1.08:../../devel/p5-IO-Tty

USE_TOOLS+=		perl # for self-tests (!?)
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IPC/Run/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
