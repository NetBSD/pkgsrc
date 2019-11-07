# $NetBSD: Makefile,v 1.1 2019/11/07 10:21:43 he Exp $

DISTNAME=	Alien-Libxml2-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Alien::Libxml2
COMMENT=	Perl interface to libxml2
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Alien/Libxml2/.packlist

DEPENDS+=	p5-Alien-Build>=1.60:../../devel/p5-Alien-Build

#INSTALLATION_DIRS+=	${EGSUBDIR}

#pre-configure:
#	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
