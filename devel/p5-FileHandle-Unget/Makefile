# $NetBSD: Makefile,v 1.1.1.1 2004/05/07 13:32:59 wiz Exp $

DISTNAME=	FileHandle-Unget-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FileHandle/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dcoppit/FileHandle-Unget/
COMMENT=	Perl5 module providing an improved filehandle

DEPENDS+=	p5-WeakRef-[0-9]*:../../devel/p5-WeakRef

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/FileHandle/Unget/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
