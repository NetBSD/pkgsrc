# $NetBSD: Makefile,v 1.3 2008/11/16 23:42:34 he Exp $
#

DISTNAME=	FileHandle-Fmode-0.11
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
