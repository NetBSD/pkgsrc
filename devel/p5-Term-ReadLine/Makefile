# $NetBSD: Makefile,v 1.46 2016/07/28 02:56:49 wen Exp $

DISTNAME=	Term-ReadLine-Gnu-1.34
PKGNAME=	p5-${DISTNAME:S/-Gnu//}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ReadLine-Gnu/
COMMENT=	Interface to the GNU Readline Library
LICENSE=	${PERL5_LICENSE} # see README

PERL5_PACKLIST=		auto/Term/ReadLine/Gnu/.packlist

MAKE_PARAMS+=	--prefix=${BUILDLINK_PREFIX.readline}

WRKSRC=		${WRKDIR}/${DISTNAME:C/a$//}

REPLACE_PERL+=	Gnu/XS.pm

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
