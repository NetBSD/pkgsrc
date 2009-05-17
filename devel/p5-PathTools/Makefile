# $NetBSD: Makefile,v 1.10 2009/05/17 14:47:12 sno Exp $

DISTNAME=	PathTools-3.30
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PathTools/
COMMENT=	Perl module for portably manipulating file specifications
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=1.14}:../../devel/p5-Scalar-List-Utils

CONFLICTS+=	p5-File-Spec-[0-9]*

CONFIGURE_ARGS+=	DEFINE="-DHAS_GETCWD"

PERL5_PACKLIST=	auto/Cwd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
