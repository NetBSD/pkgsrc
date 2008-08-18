# $NetBSD: Makefile,v 1.1.1.1 2008/08/18 22:10:49 seb Exp $
#

DISTNAME=	File-Path-Expand-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Path-Expand/
COMMENT=	Perl 5 module to expand filenames

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/Path/Expand/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
