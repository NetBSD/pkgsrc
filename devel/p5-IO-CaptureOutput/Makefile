# $NetBSD: Makefile,v 1.6 2012/10/03 21:55:07 wiz Exp $

DISTNAME=	IO-CaptureOutput-1.1102
PKGNAME=	p5-${DISTNAME:S/1102/11.02/}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-CaptureOutput/
COMMENT=	Perl module capture STDOUT and STDERR from Perl code, subprocesses or XS
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/IO/CaptureOutput/.packlist

DEPENDS+=	{perl>=5.8.9,p5-PathTools>=3.27}:../../devel/p5-PathTools

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
