# $NetBSD: Makefile,v 1.1.1.1 2007/05/27 19:42:32 heinz Exp $
#

DISTNAME=	File-Tempdir-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Tempdir/
COMMENT=	Object interface for tempdir() from Perl module File::Temp

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/Tempdir/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
