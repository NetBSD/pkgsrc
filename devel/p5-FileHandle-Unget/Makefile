# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:21 jlam Exp $

DISTNAME=	FileHandle-Unget-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FileHandle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dcoppit/FileHandle-Unget/
COMMENT=	Perl5 module providing an improved filehandle

DEPENDS+=	p5-WeakRef-[0-9]*:../../devel/p5-WeakRef

PERL5_PACKLIST=		auto/FileHandle/Unget/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
