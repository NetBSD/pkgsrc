# $NetBSD: Makefile,v 1.1.1.1 2008/08/23 19:39:16 seb Exp $
#

DISTNAME=	FileHandle-Fmode-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FileHandle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FileHandle-Fmode/
COMMENT=	Perl 5 module to determine how a filehandle is opened

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/FileHandle/Fmode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
