# $NetBSD: Makefile,v 1.9 2021/04/21 11:42:47 adam Exp $

DISTNAME=	Alien-Libxml2-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Alien::Libxml2
COMMENT=	Perl interface to libxml2
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Alien/Libxml2/.packlist

DEPENDS+=	p5-Alien-Build>=1.60:../../devel/p5-Alien-Build
DEPENDS+=	p5-PkgConfig>=0.24026:../../devel/p5-PkgConfig

#INSTALLATION_DIRS+=	${EGSUBDIR}

#pre-configure:
#	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
