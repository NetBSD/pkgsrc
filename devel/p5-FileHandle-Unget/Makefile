# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:32 tv Exp $

DISTNAME=	FileHandle-Unget-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FileHandle/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dcoppit/FileHandle-Unget/
COMMENT=	Perl5 module providing an improved filehandle

DEPENDS+=	p5-WeakRef-[0-9]*:../../devel/p5-WeakRef

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/FileHandle/Unget/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
