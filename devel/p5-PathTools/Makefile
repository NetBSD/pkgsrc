# $NetBSD: Makefile,v 1.14 2011/08/14 12:26:30 obache Exp $

DISTNAME=	PathTools-3.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PathTools/
COMMENT=	Perl module for portably manipulating file specifications
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=1.14}:../../devel/p5-Scalar-List-Utils

CONFLICTS+=	p5-File-Spec-[0-9]*

CFLAGS+=	-DHAS_GETCWD

PERL5_PACKLIST=	auto/Cwd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
