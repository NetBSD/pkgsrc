# $NetBSD: Makefile,v 1.1 2009/02/25 22:29:26 sno Exp $

DISTNAME=	IO-CaptureOutput-1.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-CaptureOutput/
COMMENT=	Perl module capture STDOUT and STDERR from Perl code, subprocesses or XS

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/IO/CaptureOutput/.packlist

DEPENDS+=	p5-PathTools>=3.27:../../devel/p5-PathTools

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
