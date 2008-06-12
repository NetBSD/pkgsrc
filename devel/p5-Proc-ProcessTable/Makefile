# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:25 joerg Exp $
#

DISTNAME=		Proc-ProcessTable-0.41
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl extension to access the UNIX process table

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL=		example.pl

PERL5_PACKLIST=		auto/Proc/ProcessTable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
