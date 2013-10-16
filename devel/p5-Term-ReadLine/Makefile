# $NetBSD: Makefile,v 1.33 2013/10/16 16:34:37 roy Exp $

DISTNAME=	Term-ReadLine-Gnu-1.20
PKGNAME=	p5-${DISTNAME:S/-Gnu//}
PKGREVISION=	5
SVR4_PKGNAME=	p5trl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ReadLine-Gnu/
COMMENT=	Interface to the GNU Readline Library
LICENSE=	${PERL5_LICENSE} # see README

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Term/ReadLine/Gnu/.packlist

MAKE_PARAMS+=	--includedir=${PREFIX}/include --libdir=${PREFIX}/lib

WRKSRC=		${WRKDIR}/${DISTNAME:C/a$//}

REPLACE_PERL+=	Gnu/XS.pm Gnu/euc_jp.pm

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
