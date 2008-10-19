# $NetBSD: Makefile,v 1.7 2008/10/19 19:17:58 he Exp $

DISTNAME=	PathTools-3.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PathTools/
COMMENT=	Perl module for portably manipulating file specifications

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Scalar-List-Utils>=1.14:../../devel/p5-Scalar-List-Utils

CONFLICTS+=	p5-File-Spec-[0-9]*

CONFIGURE_ARGS+=	DEFINE="-DHAS_GETCWD"

PERL5_PACKLIST=	auto/Cwd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
