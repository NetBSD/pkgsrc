# $NetBSD: Makefile,v 1.11 2025/07/04 08:46:42 wiz Exp $

DISTNAME=	Term-ReadLine-Gnu-1.46
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-ReadLine-Gnu
COMMENT=	Perl extension for the GNU Readline/History Library
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Term/ReadLine/Gnu/.packlist

.include "../../lang/perl5/module.mk"
# does not accept editline
.include "../../devel/readline/buildlink3.mk"
.if empty(USE_BUILTIN.readline:L:Myes)
MAKE_PARAMS+=	--libdir=${PREFIX}/lib
.endif
.include "../../mk/bsd.pkg.mk"
