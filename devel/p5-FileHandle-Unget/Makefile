# $NetBSD: Makefile,v 1.9 2008/08/05 10:12:54 he Exp $

DISTNAME=	FileHandle-Unget-0.1622
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FileHandle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FileHandle-Unget/
COMMENT=	Perl5 module providing an improved filehandle

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/FileHandle/Unget/.packlist

# for tests:
USE_TOOLS+=	perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
