# $NetBSD: Makefile,v 1.2 2009/05/21 15:38:30 sno Exp $

DISTNAME=	IO-CaptureOutput-1.1101
PKGNAME=	p5-${DISTNAME:S/1101/11.01/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-CaptureOutput/
COMMENT=	Perl module capture STDOUT and STDERR from Perl code, subprocesses or XS
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/IO/CaptureOutput/.packlist

DEPENDS+=	p5-PathTools>=3.27:../../devel/p5-PathTools

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
