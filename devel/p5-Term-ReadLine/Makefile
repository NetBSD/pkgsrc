# $NetBSD: Makefile,v 1.54 2020/08/31 18:08:56 wiz Exp $

DISTNAME=	Term-ReadLine-Gnu-1.36
PKGNAME=	p5-${DISTNAME:S/-Gnu//}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-ReadLine-Gnu
COMMENT=	Interface to the GNU Readline Library
LICENSE=	${PERL5_LICENSE} # see README

PERL5_PACKLIST=		auto/Term/ReadLine/Gnu/.packlist

MAKE_PARAMS+=	--prefix=${BUILDLINK_PREFIX.readline}

WRKSRC=		${WRKDIR}/${DISTNAME:C/a$//}

BROKEN_READLINE_DETECTION=	yes

REPLACE_PERL+=	Gnu/XS.pm

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
