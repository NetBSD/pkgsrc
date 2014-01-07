# $NetBSD: Makefile,v 1.12 2014/01/07 19:40:41 jperkin Exp $
#

DISTNAME=		Proc-ProcessTable-0.45
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Proc-ProcessTable/
COMMENT=		Perl extension to access the UNIX process table

PKG_INSTALLATION_TYPES=	overwrite pkgviews

REPLACE_PERL=		example.pl

PERL5_PACKLIST=		auto/Proc/ProcessTable/.packlist

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
