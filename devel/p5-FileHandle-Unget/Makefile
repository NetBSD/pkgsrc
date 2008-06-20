# $NetBSD: Makefile,v 1.8 2008/06/20 01:09:15 joerg Exp $

DISTNAME=	FileHandle-Unget-0.1621
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FileHandle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dcoppit/FileHandle-Unget/
COMMENT=	Perl5 module providing an improved filehandle

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/FileHandle/Unget/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
